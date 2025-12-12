#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void pausar(void) {
    printf("\nPressione ENTER para continuar...");
    // Ler até newline
    int c = getchar();
    (void)c;
}

int lerInteiroSeguro(void) {
    char linha[64];

    while (1) {
        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            // entrada inválida, pedir novamente
            printf("Entrada invalida. Digite novamente: ");
            continue;
        }

        // remover newline
        linha[strcspn(linha, "\n")] = '\0';

        //pergunta se permiti hífen? não, apenas dígitos (positivo)
        int valido = 1;
        if (linha[0] == '\0') valido = 0;
        for (size_t i = 0; linha[i] != '\0'; i++) {
            if (!isdigit((unsigned char)linha[i])) {
                valido = 0;
                break;
            }
        }

        if (!valido) {
            printf("Apenas numeros inteiros positivos são permitidos. Digite novamente: ");
            continue;
        }

        return atoi(linha);
    }
}

void lerStringSegura(char *dest, size_t max) {
    while (1) {
        if (fgets(dest, (int)max, stdin) == NULL) {
            printf("Entrada inválida. Digite novamente: ");
            continue;
        }

        dest[strcspn(dest, "\n")] = '\0';

        // remover espaços iniciais e finais
        
        size_t start = 0;
        while (dest[start] != '\0' && isspace((unsigned char)dest[start])) start++;
       
        size_t end = strlen(dest);
        while (end > start && isspace((unsigned char)dest[end - 1])) end--;

        if (end - start == 0) {
            printf("O campo não pode ficar vazio. Digite novamente: ");
            continue;
        }


        if (start > 0) {
            size_t j = 0;
            for (size_t i = start; i < end; i++, j++) dest[j] = dest[i];
            dest[end - start] = '\0';
        } else {
            dest[end] = '\0';
        }

        return;
    }
}

int lerStringOpcional(char *dest, size_t max) {
    if (fgets(dest, (int)max, stdin) == NULL) {
        dest[0] = '\0';
        return 0;
    }

    dest[strcspn(dest, "\n")] = '\0';

    size_t start = 0;
    while (dest[start] != '\0' && isspace((unsigned char)dest[start])) start++;
    size_t end = strlen(dest);
    while (end > start && isspace((unsigned char)dest[end - 1])) end--;

    if (end - start == 0) {
        dest[0] = '\0';
        return 0;
    }

    if (start > 0) {
        size_t j = 0;
        for (size_t i = start; i < end; i++, j++) dest[j] = dest[i];
        dest[end - start] = '\0';
    } else {
        dest[end] = '\0';
    }

    return 1;
}

#include <string.h>
#include "ordenacao.h"

static void trocar(Profissional *a, Profissional *b) {
    Profissional temp = *a;
    *a = *b;
    *b = temp;
}

void ordenarPorNome(Profissional lista[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(lista[j].nome, lista[j + 1].nome) > 0) {
                trocar(&lista[j], &lista[j + 1]);
            }
        }
    }
}

void ordenarPorArea(Profissional lista[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(lista[j].area, lista[j + 1].area) > 0) {
                trocar(&lista[j], &lista[j + 1]);
            }
        }
    }
}

void ordenarPorId(Profissional lista[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (lista[j].id > lista[j + 1].id) {
                trocar(&lista[j], &lista[j + 1]);
            }
        }
    }
}

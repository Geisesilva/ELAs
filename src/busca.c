#include <stdio.h>
#include <string.h> //Usado para strstr
#include "busca.h"
#include "utils.h"

void buscarPorNome(Profissional lista[], int count, const char *nome) {
    int encontrados = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(lista[i].nome, nome) != NULL) { //Procura nome dentro de lista[i].nome
            printf("\nID: %d\n", lista[i].id);
            printf("Nome: %s\n", lista[i].nome);
            printf("Area: %s\n", lista[i].area);
            printf("Contato: %s\n", lista[i].contato);
            printf("Descricao: %s\n", lista[i].descricao);
            printf("----------------------------------------------------\n");
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhuma profissional encontrada com esse nome.\n");
    }
}
void buscarPorArea(Profissional lista[], int count, const char *area) {
    int encontrados = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(lista[i].area, area) != NULL) {
            printf("\nID: %d\n", lista[i].id);
            printf("Nome: %s\n", lista[i].nome);
            printf("Area: %s\n", lista[i].area);
            printf("Contato: %s\n", lista[i].contato);
            printf("Descricao: %s\n", lista[i].descricao);
            printf("----------------------------------------------------\n");
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhuma profissional encontrada nessa area.\n");
    }
}

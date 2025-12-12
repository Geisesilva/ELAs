#include <stdio.h>
#include <string.h>
#include "profissional.h"
#include "utils.h"

static int gerarNovoId(Profissional lista[], int count) {
    int maxId = 0;
    for (int i = 0; i < count; i++) {
        if (lista[i].id > maxId) maxId = lista[i].id;
    }
    return maxId + 1;
}

int cadastrar(Profissional lista[], int count) { //Cadastro de profissionais.
    if (count >= MAX_PROFISSIONAIS) {
        printf("Limite maximo de cadastros atingido.\n");
        return count;
    }

    Profissional p;
    p.id = gerarNovoId(lista, count);

    printf("Nome: ");
    lerStringSegura(p.nome, sizeof(p.nome));

    printf("Area: ");
    lerStringSegura(p.area, sizeof(p.area));

    printf("Contato: ");
    lerStringSegura(p.contato, sizeof(p.contato));

    printf("Descricao: ");
    lerStringSegura(p.descricao, sizeof(p.descricao));

    lista[count] = p;
    printf("Profissional cadastrada com sucesso! (ID: %d)\n", p.id);
    return count + 1;
}

void listar(Profissional lista[], int count) { //Para listar os profissionais cadastrados.
    if (count == 0) {
        printf("Nenhuma profissional cadastrada.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d\n", lista[i].id);
        printf("Nome: %s\n", lista[i].nome);
        printf("Area: %s\n", lista[i].area);
        printf("Contato: %s\n", lista[i].contato);
        printf("Descricao: %s\n", lista[i].descricao);
        printf("----------------------------------------------------\n");
    }
}
//Aqui temos a busca por ID, edição e botão de exclusão.
int buscarPorId(Profissional lista[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (lista[i].id == id) return i;
    }
    return -1;
}

void editar(Profissional lista[], int count, int id) {
    int idx = buscarPorId(lista, count, id);
    if (idx == -1) {
        printf("ID não encontrado.\n");
        return;
    }

    char buffer[300];

    printf("Novo nome (enter para manter): ");
    if (lerStringOpcional(buffer, sizeof(buffer))) {
        strncpy(lista[idx].nome, buffer, sizeof(lista[idx].nome));
        lista[idx].nome[sizeof(lista[idx].nome)-1] = '\0';
    }

    printf("Nova area (enter para manter): ");
    if (lerStringOpcional(buffer, sizeof(buffer))) {
        strncpy(lista[idx].area, buffer, sizeof(lista[idx].area));
        lista[idx].area[sizeof(lista[idx].area)-1] = '\0';
    }

    printf("Novo contato (enter para manter): ");
    if (lerStringOpcional(buffer, sizeof(buffer))) {
        strncpy(lista[idx].contato, buffer, sizeof(lista[idx].contato));
        lista[idx].contato[sizeof(lista[idx].contato)-1] = '\0';
    }

    printf("Nova descricao (enter para manter): ");
    if (lerStringOpcional(buffer, sizeof(buffer))) {
        strncpy(lista[idx].descricao, buffer, sizeof(lista[idx].descricao));
        lista[idx].descricao[sizeof(lista[idx].descricao)-1] = '\0';
    }

    printf("Registro atualizado com sucesso.\n");
}

int excluir(Profissional lista[], int count, int id) {
    int idx = buscarPorId(lista, count, id);
    if (idx == -1) {
        printf("ID nao encontrado.\n");
        return count;
    }

    for (int i = idx; i < count - 1; i++) {
        lista[i] = lista[i + 1];
    }

    printf("Registro excluído.\n");
    return count - 1;
}

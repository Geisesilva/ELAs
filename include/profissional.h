#ifndef PROFISSIONAL_H
#define PROFISSIONAL_H

#define MAX_PROFISSIONAIS 1000

typedef struct {
    int id;
    char nome[100];
    char area[100];
    char contato[100];
    char descricao[300];
} Profissional;

/* CRUD */
int cadastrar(Profissional lista[], int count);
void listar(Profissional lista[], int count);
int buscarPorId(Profissional lista[], int count, int id);
void editar(Profissional lista[], int count, int id);
int excluir(Profissional lista[], int count, int id);

#endif
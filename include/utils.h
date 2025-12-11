#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

/* Limpa stdin */
void limparBuffer(void);

/* Pausa aguardando ENTER */
void pausar(void);

/* Lê e valida um inteiro (apenas dígitos). Retorna o valor inteiro. */
int lerInteiroSeguro(void);

/* Lê uma string e garante que não fique vazia. */
void lerStringSegura(char *dest, size_t max);

/* Lê uma string opcional: retorna 1 se foi digitada algo não vazio, 0 se ENTER apenas.
   Se algo foi digitado, dest recebe o texto (sem newline). */
int lerStringOpcional(char *dest, size_t max);

#endif
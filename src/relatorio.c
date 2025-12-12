#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
  #include <direct.h>
  #define MKDIR(path) _mkdir(path)
#else
  #include <sys/stat.h>
  #define MKDIR(path) mkdir(path, 0777)
#endif

#include "relatorio.h"
#include "profissional.h"

static void garantirPastaData(void) {
    /* tenta criar; caso já exista, ignora erro */
    MKDIR("data");
}

void gerarRelatorio(Profissional lista[], int count) {
    garantirPastaData();

    FILE *f = fopen("data/relatorio_elas.txt", "w");
    if (f == NULL) {
        printf("Erro ao criar o relatorio.\n");
        return;
    }

    time_t agora = time(NULL); //pegar o horário atual
    struct tm *t = localtime(&agora); //localtime: transforma em dada e hora legivel

    fprintf(f, "====================================================\n");
    fprintf(f, "                     RELATÓRIO ELAs\n");
    fprintf(f, "====================================================\n");
    fprintf(f, "Gerado em: %02d/%02d/%04d às %02d:%02d\n\n",
            t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
            t->tm_hour, t->tm_min);

    if (count == 0) {
        fprintf(f, "Nenhuma profissional cadastrada.\n"); //escreve texto no arquivo.
    } else {
        for (int i = 0; i < count; i++) {
            fprintf(f, "ID: %d\n", lista[i].id);
            fprintf(f, "Nome: %s\n", lista[i].nome);
            fprintf(f, "Area: %s\n", lista[i].area);
            fprintf(f, "Contato: %s\n", lista[i].contato);
            fprintf(f, "Descricao: %s\n", lista[i].descricao);
            fprintf(f, "----------------------------------------------------\n");
        }
    }

    fprintf(f, "\nFim do relatorio.\n");
    fprintf(f, "====================================================\n");

    fclose(f);

    printf("Relatorio gerado com sucesso em: data/relatorio_elas.txt\n");
}

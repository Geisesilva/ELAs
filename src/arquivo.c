#include <stdio.h>
#include <sys/stat.h>
#include <strings.h>
#include "arquivo.h"

static const char *CAMINHO = "data/elas.bin";

static void garantirPasta() {
#ifdef _WIN32
    mkdir("data");
#else
    mkdir("data", 0777);
#endif
}

int carregarArquivo(Profissional lista[], int max) {
    garantirPasta();

    FILE *f = fopen(CAMINHO, "rb");
    if (!f) {
        return 0; // arquivo ainda não existe, lista vazia
    }

    int count = fread(lista, sizeof(Profissional), max, f);
    fclose(f);
    return count;
}

void salvarArquivo(Profissional lista[], int count) {
    garantirPasta();

    FILE *f = fopen(CAMINHO, "wb");
    if (!f) {
        printf("Erro ao salvar arquivo.\n");
        return;
    }

    fwrite(lista, sizeof(Profissional), count, f);
    fclose(f);
}

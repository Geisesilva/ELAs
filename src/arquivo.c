#include <stdio.h>
#include <sys/stat.h> //Biblioteca que permite criar pastas e mexer com permissões de arquivos no Linux.
#include <strings.h>
#include "arquivo.h"

static const char *CAMINHO = "data/elas.bin"; //Define uma constante que guarda o caminho do arquivo binário.

static void garantirPasta() { //Serve para criar a pasta /data.
#ifdef _WIN32 //Para compilar no Windows.
    mkdir("data"); //cria a pasta.
#else
    mkdir("data", 0777); //para Linux e MacOS.
#endif
}

int carregarArquivo(Profissional lista[], int max) { 
    garantirPasta();

    FILE *f = fopen(CAMINHO, "rb"); //Abre o arquivo binário
    if (!f) {
        return 0; //se o arquivo ainda não existe, lista vazia
    }

    int count = fread(lista, sizeof(Profissional), max, f); /*lê vários registros de uma vez e
    coloca dentro do array lista.*/
    fclose(f);
    return count;
}

void salvarArquivo(Profissional lista[], int count) {
    garantirPasta();

    FILE *f = fopen(CAMINHO, "wb"); //Abre o arquivo binário para escrita.
    if (!f) {
        printf("Erro ao salvar arquivo.\n");
        return;
    }

    fwrite(lista, sizeof(Profissional), count, f); // Escreve TODOS os registros no arquivo de uma só vez.
    fclose(f);
}

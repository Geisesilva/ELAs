#include "profissional.h"
#include "arquivo.h"
#include "interface.h"

int main() {
    Profissional lista[1000]; //Cria um vetor com até 1000 profissionais.
    int count = carregarArquivo(lista, 1000); //Carrega os dados já existentes.

    menuPrincipal(lista, &count); //Roda o menu.

    salvarArquivo(lista, count); //Salva
    return 0;
}

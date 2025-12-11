#include "profissional.h"
#include "arquivo.h"
#include "interface.h"

int main() {
    Profissional lista[1000];
    int count = carregarArquivo(lista, 1000);

    menuPrincipal(lista, &count);

    salvarArquivo(lista, count);
    return 0;
}

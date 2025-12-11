#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "arquivo.h"
#include "busca.h"
#include "ordenacao.h"
#include "relatorio.h"
#include "utils.h"

void menuPrincipal(Profissional lista[], int *count) {
    int opcao;

    do {
        system("cls || clear");

        printf("\n====================================================\n");
        printf("                     SISTEMA ELAs\n");
        printf("      Gestão de Profissionais Feita para Mulheres\n");
        printf("====================================================\n\n");

        printf("  1. Cadastrar profissional\n");
        printf("  2. Listar profissionais\n");
        printf("  3. Editar profissional\n");
        printf("  4. Excluir profissional\n");
        printf("  5. Buscar por nome\n");
        printf("  6. Buscar por área\n");
        printf("  7. Ordenar por nome\n");
        printf("  8. Ordenar por área\n");
        printf("  9. Ordenar por ID\n");
        printf(" 10. Gerar relatório em arquivo .txt\n");
        printf(" 11. Salvar dados\n");
        printf(" 12. Sair do sistema\n");

        printf("\n----------------------------------------------------\n");
        printf("Escolha uma opção: ");

        opcao = lerInteiroSeguro();  /* usa validação */
        printf("\n");

        switch (opcao) {

            case 1:
                *count = cadastrar(lista, *count);
                pausar();
                break;

            case 2:
                listar(lista, *count);
                pausar();
                break;

            case 3: {
                int id;
                printf("Digite o ID da profissional: ");
                id = lerInteiroSeguro();
                editar(lista, *count, id);
                pausar();
                break;
            }

            case 4: {
                int id;
                printf("Digite o ID da profissional: ");
                id = lerInteiroSeguro();
                *count = excluir(lista, *count, id);
                pausar();
                break;
            }

            case 5: {
                char nome[100];
                printf("Digite o nome para buscar: ");
                lerStringSegura(nome, sizeof(nome));
                buscarPorNome(lista, *count, nome);
                pausar();
                break;
            }

            case 6: {
                char area[100];
                printf("Digite a área para buscar: ");
                lerStringSegura(area, sizeof(area));
                buscarPorArea(lista, *count, area);
                pausar();
                break;
            }

            case 7:
                ordenarPorNome(lista, *count);
                printf("Lista ordenada por nome.\n");
                pausar();
                break;

            case 8:
                ordenarPorArea(lista, *count);
                printf("Lista ordenada por área.\n");
                pausar();
                break;

            case 9:
                ordenarPorId(lista, *count);
                printf("Lista ordenada por ID.\n");
                pausar();
                break;

            case 10:
                gerarRelatorio(lista, *count);
                pausar();
                break;

            case 11:
                salvarArquivo(lista, *count);
                printf("Dados salvos com sucesso.\n");
                pausar();
                break;

            case 12:
                printf("Encerrando o sistema... até logo!\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                pausar();
        }

    } while (opcao != 12);
}
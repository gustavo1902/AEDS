#include <stdio.h>

int main() {
    int matriz[3][3];
    int linha, coluna, valor;
    int opcao;

    printf("Matriz 3x3\n");

    // Inicialização da matriz com zeros
    for (linha = 0; linha < 3; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
            matriz[linha][coluna] = 0;
        }
    }

    // Menu de opções
    do {
        printf("\nOpções:\n");
        printf("1. Inserir elemento\n");
        printf("2. Alterar elemento\n");
        printf("3. Consultar elemento\n");
        printf("0. Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // Inserir elemento
                printf("Digite a linha (0 a 2): ");
                scanf("%d", &linha);
                printf("Digite a coluna (0 a 2): ");
                scanf("%d", &coluna);
                printf("Digite o valor: ");
                scanf("%d", &valor);

                if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {
                    matriz[linha][coluna] = valor;
                    printf("Elemento inserido com sucesso!\n");
                } else {
                    printf("Posição inválida!\n");
                }
                break;

            case 2: // Alterar elemento
                printf("Digite a linha (0 a 2): ");
                scanf("%d", &linha);
                printf("Digite a coluna (0 a 2): ");
                scanf("%d", &coluna);
                printf("Digite o novo valor: ");
                scanf("%d", &valor);

                if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {
                    matriz[linha][coluna] = valor;
                    printf("Elemento alterado com sucesso!\n");
                } else {
                    printf("Posição inválida!\n");
                }
                break;

            case 3: // Consultar elemento
                printf("Digite a linha (0 a 2): ");
                scanf("%d", &linha);
                printf("Digite a coluna (0 a 2): ");
                scanf("%d", &coluna);

                if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {
                    printf("Elemento na posição (%d, %d): %d\n", linha, coluna, matriz[linha][coluna]);
                } else {
                    printf("Posição inválida!\n");
                }
                break;

            case 0: // Sair
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }

        // Exibir a matriz atualizada
        printf("\nMatriz Atual:\n");
        for (linha = 0; linha < 3; linha++) {
            for (coluna = 0; coluna < 3; coluna++) {
                printf("%d ", matriz[linha][coluna]);
            }
            printf("\n");
        }

    } while (opcao != 0);

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char nomes[5][50]; // Vetor para armazenar os nomes, cada nome pode ter até 50 caracteres
    int opcao, posicao;

    // Loop principal do programa
    do {
        printf("\nMenu:\n");
        printf("1. Inserir nome\n");
        printf("2. Alterar nome\n");
        printf("3. Consultar nome\n");
        printf("4. Sair\n");

        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Inserir nome
                printf("Digite a posição (0 a 4) para inserir o nome: ");
                scanf("%d", &posicao);

                if (posicao >= 0 && posicao < 5) {
                    printf("Digite o nome: ");
                    scanf("%s", nomes[posicao]);
                    printf("Nome inserido com sucesso!\n");
                } else {
                    printf("Posição inválida!\n");
                }
                break;
            case 2:
                // Alterar nome
                printf("Digite a posição (0 a 4) para alterar o nome: ");
                scanf("%d", &posicao);

                if (posicao >= 0 && posicao < 5) {
                    printf("Digite o novo nome: ");
                    scanf("%s", nomes[posicao]);
                    printf("Nome alterado com sucesso!\n");
                } else {
                    printf("Posição inválida!\n");
                }
                break;
            case 3:
                // Consultar nome
                printf("Digite a posição (0 a 4) para consultar o nome: ");
                scanf("%d", &posicao);

                if (posicao >= 0 && posicao < 5) {
                    printf("Nome na posição %d: %s\n", posicao, nomes[posicao]);
                } else {
                    printf("Posição inválida!\n");
                }
                break;
            case 4:
                // Sair
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 4);

    return 0;
}

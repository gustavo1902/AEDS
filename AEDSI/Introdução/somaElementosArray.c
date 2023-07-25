#include <stdio.h>

int main() {
    int tamanho;
    printf("Calculadora de Soma de Elementos em um Array\n\n");

    // Solicitar ao usuário o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    // Criar o array de acordo com o tamanho informado
    int array[tamanho];

    // Solicitar ao usuário os elementos do array
    printf("Digite os %d elementos do array:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Calcular a soma dos elementos do array
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }

    // Exibir o resultado da soma
    printf("\nA soma dos elementos do array é: %d\n", soma);

    return 0;
}

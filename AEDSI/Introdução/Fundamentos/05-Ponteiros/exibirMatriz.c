#include <stdio.h>

int main() {
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }; // Matriz de números inteiros
    int *ponteiro; // Ponteiro para um número inteiro
    int i, j;

    ponteiro = &matriz[0][0]; // Atribuir o endereço do primeiro elemento da matriz ao ponteiro

    // Exibir os elementos da matriz através do ponteiro
    printf("Elementos da matriz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", *ponteiro);
            ponteiro++; // Avançar o ponteiro para o próximo elemento da matriz
        }
        printf("\n");
    }

    return 0;
}

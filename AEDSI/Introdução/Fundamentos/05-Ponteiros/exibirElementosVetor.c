#include <stdio.h>

int main() {
    int vetor[5] = {10, 20, 30, 40, 50}; // Vetor de números inteiros
    int *ponteiro;                       // Ponteiro para um número inteiro
    int i;

    ponteiro = vetor; // Atribuir o endereço do primeiro elemento do vetor ao ponteiro

    // Exibir os elementos do vetor através do ponteiro
    printf("Elementos do vetor: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", *ponteiro);
        ponteiro++; // Avançar o ponteiro para o próximo elemento do vetor
    }
    printf("\n");

    return 0;
}

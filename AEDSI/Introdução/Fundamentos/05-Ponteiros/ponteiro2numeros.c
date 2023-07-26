#include <stdio.h>

int main() {
    int numero = 10; // Variável inteira
    int *ponteiro;   // Ponteiro para um número inteiro

    ponteiro = &numero; // Atribuir o endereço da variável 'numero' ao ponteiro

    printf("Valor original da variável: %d\n", numero);

    // Alterar o valor da variável através do ponteiro
    *ponteiro = 20;

    printf("Novo valor da variável: %d\n", numero);

    return 0;
}

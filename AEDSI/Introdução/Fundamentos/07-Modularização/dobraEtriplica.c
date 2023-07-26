#include <stdio.h>

// Função para dobrar o valor de um número (passagem por valor)
int dobrarPorValor(int num) {
    return num * 2;
}

// Função para triplicar o valor de um número (passagem por referência)
void triplicarPorReferencia(int *num) {
    *num = *num * 3;
}

int main() {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    // Chama a função de dobrar com a passagem por valor
    int dobrado = dobrarPorValor(numero);

    // Chama a função de triplicar com a passagem por referência
    triplicarPorReferencia(&numero);

    printf("O número dobrado é: %d\n", dobrado);
    printf("O número triplicado é: %d\n", numero);

    return 0;
}

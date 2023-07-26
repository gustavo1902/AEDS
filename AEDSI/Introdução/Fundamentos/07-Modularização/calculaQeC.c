#include <stdio.h>

// Função para calcular o quadrado de um número
int calcularQuadrado(int num) {
    return num * num;
}

// Função para calcular o cubo de um número
int calcularCubo(int num) {
    return num * num * num;
}

int main() {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    // Chama as funções para calcular o quadrado e o cubo do número digitado
    int quadrado = calcularQuadrado(numero);
    int cubo = calcularCubo(numero);

    printf("O quadrado de %d é: %d\n", numero, quadrado);
    printf("O cubo de %d é: %d\n", numero, cubo);

    return 0;
}

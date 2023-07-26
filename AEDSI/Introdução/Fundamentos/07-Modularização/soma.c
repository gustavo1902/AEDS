#include <stdio.h>

// Função para realizar a soma de dois números
int somar(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    // Chama a função de soma com os parâmetros reais num1 e num2
    int resultado = somar(num1, num2);

    printf("A soma dos números é: %d\n", resultado);

    return 0;
}

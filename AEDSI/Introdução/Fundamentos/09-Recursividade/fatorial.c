#include <stdio.h>

// Função recursiva para calcular o fatorial
int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

int main() {
    int numero;

    printf("Digite um numero inteiro nao negativo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Erro: Numero deve ser nao negativo.\n");
    } else {
        int resultado = fatorial(numero);
        printf("O fatorial de %d eh: %d\n", numero, resultado);
    }

    return 0;
}

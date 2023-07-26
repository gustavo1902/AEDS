#include <stdio.h>

// Algoritmo Recursivo
int fatorialRecursivo(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fatorialRecursivo(n - 1);
}

// Algoritmo de Força Bruta
int fatorialForcaBruta(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Algoritmo Guloso usando Fatores Primos
int fatorialGuloso(int n) {
    int resultado = 1;
    int fator = 2;

    while (n > 1) {
        if (n % fator == 0) {
            resultado *= fator;
            n /= fator;
        } else {
            fator++;
        }
    }

    return resultado;
}

int main() {
    int n;
    printf("Digite um número inteiro não negativo: ");
    scanf("%d", &n);

    printf("Fatorial (Recursivo): %d\n", fatorialRecursivo(n));
    printf("Fatorial (Força Bruta): %d\n", fatorialForcaBruta(n));
    printf("Fatorial (Guloso): %d\n", fatorialGuloso(n));

    return 0;
}

#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Digite um número inteiro não negativo: ");
    scanf("%d", &n);

    printf("O %dº número de Fibonacci é: %d\n", n, fibonacci(n));

    return 0;
}

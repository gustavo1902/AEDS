#include <stdio.h>

// Abordagem de Divisão e Conquista
int fibonacciDivConq(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciDivConq(n - 1) + fibonacciDivConq(n - 2);
}

// Abordagem de Programação Dinâmica
int fibonacciProgDinamica(int n) {
    int fib[n + 2];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    int n;
    printf("Digite um número inteiro não negativo: ");
    scanf("%d", &n);

    printf("Fibonacci (Divisão e Conquista): %d\n", fibonacciDivConq(n));
    printf("Fibonacci (Programação Dinâmica): %d\n", fibonacciProgDinamica(n));

    return 0;
}

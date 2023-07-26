#include <stdio.h>

int main() {
    int N, soma = 0;

    // Solicitar ao usuário o valor de N
    printf("Digite um número inteiro positivo N: ");
    scanf("%d", &N);

    // Calcular a soma dos N primeiros números naturais usando a estrutura iterativa "for"
    for (int i = 1; i <= N; i++) {
        soma += i;
    }

    // Exibir o resultado da soma na tela
    printf("A soma dos %d primeiros números naturais é: %d\n", N, soma);

    return 0;
}

#include <stdio.h>
#include <time.h>

int main() {
    int n, sum = 0;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    clock_t start_time = clock();

    // Cálculo da soma dos números de 1 a n
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("A soma dos números de 1 a %d é: %d\n", n, sum);
    printf("Tempo de execução: %.8f segundos.\n", time_taken);
    return 0;
}

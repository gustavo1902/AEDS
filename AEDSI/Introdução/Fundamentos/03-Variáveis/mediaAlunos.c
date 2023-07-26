#include <stdio.h>

int main() {
    int N;

    // Solicitar ao usuário o número de alunos
    printf("Digite o número de alunos: ");
    scanf("%d", &N);

    // Declarar um vetor para armazenar as notas dos alunos
    float notas[N];

    // Solicitar ao usuário as notas dos alunos e armazená-las no vetor
    for (int i = 0; i < N; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    // Calcular a média aritmética das notas
    float soma = 0;
    for (int i = 0; i < N; i++) {
        soma += notas[i];
    }
    float media = soma / N;

    // Exibir o resultado da média na tela
    printf("A média dos alunos é: %.2f\n", media);

    return 0;
}

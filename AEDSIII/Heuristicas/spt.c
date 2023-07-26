#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SPT(int tasks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (tasks[j] < tasks[min_idx]) {
                min_idx = j;
            }
        }
        swap(&tasks[i], &tasks[min_idx]);
    }
}

int main() {
    int n;
    printf("Digite o número de tarefas: ");
    scanf("%d", &n);

    int tasks[n];

    printf("Digite os tempos de execução das tarefas:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tasks[i]);
    }

    SPT(tasks, n);

    printf("Sequência ótima de execução das tarefas:\n");
    for (int i = 0; i < n; i++) {
        printf("Tarefa %d: %d unidades de tempo\n", i + 1, tasks[i]);
    }

    int totalTime = 0;
    for (int i = 0; i < n; i++) {
        totalTime += tasks[i];
    }

    printf("Tempo total necessário para completar todas as tarefas: %d unidades de tempo\n", totalTime);

    return 0;
}

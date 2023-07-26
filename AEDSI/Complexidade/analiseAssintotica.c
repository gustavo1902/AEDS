#include <stdio.h>
#include <stdlib.h>

void exibirElementos(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 10; // Tamanho do array pode ser variável
    int *arr = (int *)malloc(n * sizeof(int));

    // Verifica se a alocação foi bem-sucedida
    if (arr == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Preenche o array com valores
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Gera valores aleatórios entre 0 e 99
    }

    printf("Array original: ");
    exibirElementos(arr, n);

    // Ordenação por Seleção
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    printf("Array ordenado: ");
    exibirElementos(arr, n);

    // Libera a memória alocada
    free(arr);
    return 0;
}

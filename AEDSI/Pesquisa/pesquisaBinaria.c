#include <stdio.h>

int buscaBinaria(int arr[], int left, int right, int chave) {
    while (left <= right) {
        int meio = left + (right - left) / 2;

        if (arr[meio] == chave) {
            return meio;
        }

        if (arr[meio] < chave) {
            left = meio + 1;
        } else {
            right = meio - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int chave = 30;

    int resultado = buscaBinaria(arr, 0, size - 1, chave);

    if (resultado != -1) {
        printf("Chave encontrada no índice: %d\n", resultado);
    } else {
        printf("Chave não encontrada.\n");
    }

    return 0;
}

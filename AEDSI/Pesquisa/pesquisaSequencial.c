#include <stdio.h>

int buscaSequencial(int arr[], int size, int chave) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == chave) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int chave = 30;

    int resultado = buscaSequencial(arr, size, chave);

    if (resultado != -1) {
        printf("Chave encontrada no índice: %d\n", resultado);
    } else {
        printf("Chave não encontrada.\n");
    }

    return 0;
}

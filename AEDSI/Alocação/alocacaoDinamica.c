#include <stdio.h>
#include <stdlib.h>

// Função que aloca dinamicamente um array de inteiros com o tamanho especificado
int* alocar_array(int tamanho) {
    int* array = (int*)malloc(tamanho * sizeof(int));
    return array;
}

int main() {
    int tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    // Alocar dinamicamente o array de inteiros
    int* array = alocar_array(tamanho);

    if (array == NULL) {
        printf("Erro: Não foi possível alocar a memória.\n");
        return 1;
    }

    // Preencher o array com valores sequenciais
    for (int i = 0; i < tamanho; i++) {
        array[i] = i + 1;
    }

    // Exibir os valores do array na tela
    printf("Valores do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Liberar a memória alocada
    free(array);

    return 0;
}

#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int elementos[MAX_SIZE];
    int tamanho;
} Lista;

void inicializar_lista(Lista *lista) {
    lista->tamanho = 0;
}

int adicionar_elemento(Lista *lista, int elemento) {
    if (lista->tamanho >= MAX_SIZE) {
        printf("Erro: lista cheia!\n");
        return 0; // Falha ao adicionar
    }

    lista->elementos[lista->tamanho] = elemento;
    lista->tamanho++;
    return 1; // Sucesso ao adicionar
}

void exibir_lista(Lista *lista) {
    printf("Lista: ");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

int buscar_elemento(Lista *lista, int elemento) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == elemento) {
            return i; // Índice do elemento encontrado
        }
    }
    return -1; // Elemento não encontrado
}

int main() {
    Lista minha_lista;
    inicializar_lista(&minha_lista);

    adicionar_elemento(&minha_lista, 10);
    adicionar_elemento(&minha_lista, 20);
    adicionar_elemento(&minha_lista, 30);
    exibir_lista(&minha_lista);

    int elemento_buscar = 20;
    int indice_encontrado = buscar_elemento(&minha_lista, elemento_buscar);
    if (indice_encontrado != -1) {
        printf("O elemento %d foi encontrado na posição %d.\n", elemento_buscar, indice_encontrado);
    } else {
        printf("O elemento %d não foi encontrado na lista.\n", elemento_buscar);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
} Lista;

void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
}

void adicionar_elemento(Lista *lista, int elemento) {
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        return;
    }

    novo_no->dado = elemento;
    novo_no->proximo = lista->inicio;
    lista->inicio = novo_no;
}

void exibir_lista(Lista *lista) {
    printf("Lista: ");
    No *no_atual = lista->inicio;
    while (no_atual != NULL) {
        printf("%d ", no_atual->dado);
        no_atual = no_atual->proximo;
    }
    printf("\n");
}

int buscar_elemento(Lista *lista, int elemento) {
    No *no_atual = lista->inicio;
    int indice = 0;
    while (no_atual != NULL) {
        if (no_atual->dado == elemento) {
            return indice; // Índice do elemento encontrado
        }
        no_atual = no_atual->proximo;
        indice++;
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

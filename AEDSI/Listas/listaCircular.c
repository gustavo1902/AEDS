#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
} ListaCircular;

void inicializar_lista(ListaCircular *lista) {
    lista->inicio = NULL;
}

void adicionar_elemento(ListaCircular *lista, int elemento) {
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        return;
    }

    novo_no->dado = elemento;
    
    if (lista->inicio == NULL) {
        novo_no->proximo = novo_no; // Lista vazia, aponta para si mesmo
        lista->inicio = novo_no;
    } else {
        novo_no->proximo = lista->inicio->proximo;
        lista->inicio->proximo = novo_no;
    }
}

void exibir_lista(ListaCircular *lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista: ");
    No *no_atual = lista->inicio;
    do {
        printf("%d ", no_atual->dado);
        no_atual = no_atual->proximo;
    } while (no_atual != lista->inicio);
    printf("\n");
}

int buscar_elemento(ListaCircular *lista, int elemento) {
    if (lista->inicio == NULL) {
        return -1; // Lista vazia, elemento não encontrado
    }

    No *no_atual = lista->inicio;
    int indice = 0;
    do {
        if (no_atual->dado == elemento) {
            return indice; // Índice do elemento encontrado
        }
        no_atual = no_atual->proximo;
        indice++;
    } while (no_atual != lista->inicio);
    return -1; // Elemento não encontrado
}

int main() {
    ListaCircular minha_lista;
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

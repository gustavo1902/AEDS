#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista encadeada
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Estrutura da lista encadeada
typedef struct Lista {
    No* inicio;
} Lista;

// Função para criar uma lista vazia
Lista* criar_lista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

// Função para inserir um elemento no início da lista
void inserir_inicio(Lista* lista, int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = lista->inicio;
    lista->inicio = novo_no;
}

// Função para inserir um elemento no final da lista
void inserir_fim(Lista* lista, int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo_no;
    } else {
        No* atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
    }
}

// Função para remover o primeiro elemento da lista
void remover_inicio(Lista* lista) {
    if (lista->inicio != NULL) {
        No* temp = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        free(temp);
    }
}

// Função para remover o último elemento da lista
void remover_fim(Lista* lista) {
    if (lista->inicio != NULL) {
        No* atual = lista->inicio;
        No* anterior = NULL;
        while (atual->proximo != NULL) {
            anterior = atual;
            atual = atual->proximo;
        }
        if (anterior == NULL) {
            lista->inicio = NULL;
        } else {
            anterior->proximo = NULL;
        }
        free(atual);
    }
}

// Função para buscar um elemento na lista
No* buscar(Lista* lista, int valor) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Função para imprimir os elementos da lista
void imprimir(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para liberar a memória da lista
void liberar_lista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(lista);
}

int main() {
    Lista* lista = criar_lista();

    inserir_inicio(lista, 3);
    inserir_inicio(lista, 2);
    inserir_inicio(lista, 1);

    inserir_fim(lista, 4);
    inserir_fim(lista, 5);

    printf("Lista: ");
    imprimir(lista);

    No* elemento = buscar(lista, 3);
    if (elemento != NULL) {
        printf("Elemento encontrado: %d\n", elemento->valor);
    } else {
        printf("Elemento nao encontrado.\n");
    }

    remover_inicio(lista);
    remover_fim(lista);

    printf("Lista apos remocoes: ");
    imprimir(lista);

    liberar_lista(lista);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para o nó da lista
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Definição da estrutura para a lista encadeada
typedef struct Lista {
    No* inicio;
} Lista;

// Função para criar uma nova lista vazia
Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

// Função para inserir um valor no início da lista
void inserir(Lista* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = lista->inicio;
    lista->inicio = novoNo;
}

// Função para exibir todos os valores da lista
void exibirLista(Lista* lista) {
    No* atual = lista->inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para calcular o tamanho da lista
int tamanhoLista(Lista* lista) {
    int tamanho = 0;
    No* atual = lista->inicio;
    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;
}

// Função para liberar a memória alocada para a lista
void liberarLista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(lista);
}

int main() {
    Lista* minhaLista = criarLista();

    inserir(minhaLista, 10);
    inserir(minhaLista, 20);
    inserir(minhaLista, 30);
    inserir(minhaLista, 40);
    inserir(minhaLista, 50);

    exibirLista(minhaLista);

    printf("Tamanho da lista: %d\n", tamanhoLista(minhaLista));

    liberarLista(minhaLista);

    return 0;
}

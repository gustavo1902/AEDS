#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
    struct No *anterior;
} No;

typedef struct {
    No *inicio;
    No *fim;
} ListaDuplamenteEncadeada;

void inicializar_lista(ListaDuplamenteEncadeada *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

void adicionar_elemento_inicio(ListaDuplamenteEncadeada *lista, int elemento) {
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        return;
    }

    novo_no->dado = elemento;
    novo_no->proximo = lista->inicio;
    novo_no->anterior = NULL;

    if (lista->inicio != NULL) {
        lista->inicio->anterior = novo_no;
    } else {
        lista->fim = novo_no;
    }

    lista->inicio = novo_no;
}

void exibir_lista_direta(ListaDuplamenteEncadeada *lista) {
    printf("Lista na ordem direta: ");
    No *no_atual = lista->inicio;
    while (no_atual != NULL) {
        printf("%d ", no_atual->dado);
        no_atual = no_atual->proximo;
    }
    printf("\n");
}

void exibir_lista_reversa(ListaDuplamenteEncadeada *lista) {
    printf("Lista na ordem reversa: ");
    No *no_atual = lista->fim;
    while (no_atual != NULL) {
        printf("%d ", no_atual->dado);
        no_atual = no_atual->anterior;
    }
    printf("\n");
}

void remover_elemento(ListaDuplamenteEncadeada *lista, int elemento) {
    No *no_atual = lista->inicio;
    while (no_atual != NULL) {
        if (no_atual->dado == elemento) {
            if (no_atual == lista->inicio) {
                lista->inicio = no_atual->proximo;
                if (lista->inicio != NULL) {
                    lista->inicio->anterior = NULL;
                }
            } else if (no_atual == lista->fim) {
                lista->fim = no_atual->anterior;
                if (lista->fim != NULL) {
                    lista->fim->proximo = NULL;
                }
            } else {
                no_atual->anterior->proximo = no_atual->proximo;
                no_atual->proximo->anterior = no_atual->anterior;
            }

            free(no_atual);
            return;
        }
        no_atual = no_atual->proximo;
    }

    printf("Elemento não encontrado na lista.\n");
}

int main() {
    ListaDuplamenteEncadeada minha_lista;
    inicializar_lista(&minha_lista);

    adicionar_elemento_inicio(&minha_lista, 30);
    adicionar_elemento_inicio(&minha_lista, 20);
    adicionar_elemento_inicio(&minha_lista, 10);
    exibir_lista_direta(&minha_lista);
    exibir_lista_reversa(&minha_lista);

    remover_elemento(&minha_lista, 20);
    exibir_lista_direta(&minha_lista);

    return 0;
}

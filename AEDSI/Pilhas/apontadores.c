#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Pilha;

void inicializar_pilha(Pilha* p) {
    p->top = NULL;
}

int esta_vazia(Pilha* p) {
    return p->top == NULL;
}

void push(Pilha* p, int elemento) {
    Node* novo_no = (Node*)malloc(sizeof(Node));
    if (novo_no == NULL) {
        printf("Erro: Memória insuficiente para criar o novo nó.\n");
        return;
    }

    novo_no->data = elemento;
    novo_no->next = p->top;
    p->top = novo_no;
}

int pop(Pilha* p) {
    if (esta_vazia(p)) {
        printf("Erro: Pilha vazia, não é possível desempilhar.\n");
        return -1; // Valor inválido para representar que a pilha está vazia
    }

    Node* no_removido = p->top;
    int elemento_desempilhado = no_removido->data;
    p->top = no_removido->next;
    free(no_removido);

    return elemento_desempilhado;
}

int main() {
    Pilha minha_pilha;
    inicializar_pilha(&minha_pilha);

    push(&minha_pilha, 10);
    push(&minha_pilha, 20);
    push(&minha_pilha, 30);

    int elemento_desempilhado = pop(&minha_pilha);
    printf("Elemento desempilhado: %d\n", elemento_desempilhado);

    push(&minha_pilha, 40);
    push(&minha_pilha, 50);

    while (!esta_vazia(&minha_pilha)) {
        elemento_desempilhado = pop(&minha_pilha);
        printf("Elemento desempilhado: %d\n", elemento_desempilhado);
    }

    return 0;
}

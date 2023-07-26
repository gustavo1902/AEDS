#include <stdio.h>
#define TAM_MAX 5

typedef struct {
    int pilha[TAM_MAX];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *p) {
    p->topo = -1;
}

int esta_cheia(Pilha *p) {
    return p->topo == TAM_MAX - 1;
}

int esta_vazia(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, int elemento) {
    if (esta_cheia(p)) {
        printf("Erro: Pilha cheia, não é possível empilhar o elemento.\n");
        return;
    }

    p->topo++;
    p->pilha[p->topo] = elemento;
}

int pop(Pilha *p) {
    if (esta_vazia(p)) {
        printf("Erro: Pilha vazia, não é possível desempilhar.\n");
        return -1; // Valor inválido para representar que a pilha está vazia
    }

    int elemento_desempilhado = p->pilha[p->topo];
    p->topo--;
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

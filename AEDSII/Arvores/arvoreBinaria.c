#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
};

struct No* criarNo(int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

int main() {
    struct No* raiz = criarNo(10);
    raiz->esquerda = criarNo(5);
    raiz->direita = criarNo(15);
    raiz->esquerda->esquerda = criarNo(3);
    raiz->esquerda->direita = criarNo(7);
    raiz->direita->esquerda = criarNo(12);
    raiz->direita->direita = criarNo(18);

    // Implemente outras operações com árvores binárias aqui...

    return 0;
}

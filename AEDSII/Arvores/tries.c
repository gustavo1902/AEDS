#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALFABETO_SIZE 26

struct No {
    bool fimDePalavra;
    struct No* filho[ALFABETO_SIZE];
};

struct No* criarNo() {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->fimDePalavra = false;
    for (int i = 0; i < ALFABETO_SIZE; i++) {
        novoNo->filho[i] = NULL;
    }
    return novoNo;
}

void inserirPalavra(struct No* raiz, char* palavra) {
    struct No* atual = raiz;
    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';
        if (atual->filho[indice] == NULL) {
            atual->filho[indice] = criarNo();
        }
        atual = atual->filho[indice];
    }
    atual->fimDePalavra = true;
}

bool buscarPalavra(struct No* raiz, char* palavra) {
    struct No* atual = raiz;
    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';
        if (atual->filho[indice] == NULL) {
            return false;
        }
        atual = atual->filho[indice];
    }
    return (atual != NULL && atual->fimDePalavra);
}

int main() {
    struct No* raiz = criarNo();

    inserirPalavra(raiz, "apple");
    inserirPalavra(raiz, "banana");
    inserirPalavra(raiz, "orange");

    printf("A palavra 'apple' está na árvore? %s\n", buscarPalavra(raiz, "apple") ? "Sim" : "Não");
    printf("A palavra 'banana' está na árvore? %s\n", buscarPalavra(raiz, "banana") ? "Sim" : "Não");
    printf("A palavra 'grape' está na árvore? %s\n", buscarPalavra(raiz, "grape") ? "Sim" : "Não");

    return 0;
}

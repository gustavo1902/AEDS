#include "arvore.h"
#include <iostream>

Arvore::Arvore() {
    raiz = nullptr;
}

Arvore::~Arvore() {
    // Implementação da função destrutora da árvore (pode ser vazio, caso não seja necessário)
}

void Arvore::inserir(int chave) {
    raiz = inserir(raiz, chave);
}

Node* Arvore::inserir(Node* no, int chave) {
    if (no == nullptr) {
        no = new Node;
        no->chave = chave;
        no->esq = no->dir = nullptr;
    }
    else if (chave < no->chave) {
        no->esq = inserir(no->esq, chave);
    }
    else if (chave > no->chave) {
        no->dir = inserir(no->dir, chave);
    }
    return no;
}

void Arvore::remover(int chave) {
    raiz = remover(raiz, chave);
}

Node* Arvore::remover(Node* no, int chave) {
    if (no == nullptr) {
        return nullptr;
    }
    if (chave < no->chave) {
        no->esq = remover(no->esq, chave);
    }
    else if (chave > no->chave) {
        no->dir = remover(no->dir, chave);
    }
    else {
        if (no->esq == nullptr && no->dir == nullptr) {
            delete no;
            no = nullptr;
        }
        else if (no->esq == nullptr) {
            Node* temp = no;
            no = no->dir;
            delete temp;
        }
        else if (no->dir == nullptr) {
            Node* temp = no;
            no = no->esq;
            delete temp;
        }
        else {
            Node* temp = buscaMinimo(no->dir);
            no->chave = temp->chave;
            no->dir = remover(no->dir, temp->chave);
        }
    }
    return no;
}

Node* Arvore::buscaMinimo(Node* no) {
    Node* atual = no;
    while (atual->esq != nullptr) {
        atual = atual->esq;
    }
    return atual;
}

bool Arvore::buscar(int chave) {
    return buscar(raiz, chave);
}

using namespace std;
bool Arvore::buscar(Node* no, int chave) {
    if (no == nullptr) {
        return false;
    }
    if (chave == no->chave) {
        return true;
    }
    if (chave < no->chave) {
        return buscar(no->esq, chave);
    }
    else {
        return buscar(no->dir, chave);

    // caso a chave não seja encontrada na árvore
    cout << "Chave não encontrada na árvore!" << endl;
    return 0;
}

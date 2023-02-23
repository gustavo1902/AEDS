#ifndef ARVORE_H
#define ARVORE_H

struct Node {
    int chave;
    Node *esq, *dir;
};

class Arvore {
    public:
        Arvore();
        ~Arvore();
        void inserir(int chave);
        void remover(int chave);
        bool buscar(int chave);
        void imprimir();
    private:
        Node *raiz;
        Node* inserir(Node* no, int chave);
        Node* remover(Node* no, int chave);
        Node* buscaMinimo(Node* no);
        bool buscar(Node* no, int chave);
        void imprimir(Node* no);
};

#endif

#ifndef MAPA_H
#define MAPA_H

#include <vector>
#include "Vertice.h"
#include "Aresta.h"

class Mapa {
public:
    Mapa(int tamanho);
    ~Mapa();
    void inserirVertice(int linha, int coluna, std::string nome);
    void removerVertice(int linha, int coluna);
    void inserirAresta(int linha1, int coluna1, int linha2, int coluna2, int peso);
    void removerAresta(int linha1, int coluna1, int linha2, int coluna2);
    void imprimirMapa();

private:
    int tamanho;
    std::vector<std::vector<Vertice*>> matriz;
    bool verificaPosicao(int linha, int coluna);
};

#endif // MAPA_H

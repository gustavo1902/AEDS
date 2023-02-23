#ifndef ARESTA_H
#define ARESTA_H

#include "Vertice.h"

class Aresta {
public:
    Aresta(Vertice* origem, Vertice* destino, int peso);

    Vertice* getOrigem();
    void setOrigem(Vertice* origem);

    Vertice* getDestino();
    void setDestino(Vertice* destino);

    int getPeso();
    void setPeso(int peso);

private:
    Vertice* m_origem;
    Vertice* m_destino;
    int m_peso;
};

#endif // ARESTA_H

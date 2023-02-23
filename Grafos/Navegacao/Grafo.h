#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include "Vertice.h"
#include "Aresta.h"

class Grafo {
    private:
        std::vector<Vertice*> vertices;
        std::vector<Aresta*> arestas;
    public:
        Grafo();
        virtual ~Grafo();
        void adicionarVertice(Vertice* v);
        void adicionarAresta(Aresta* a);
        void removerVertice(Vertice* v);
        void removerAresta(Aresta* a);
};

#endif // GRAFO_H

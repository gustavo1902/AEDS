#include "Grafo.h"

Grafo::Grafo() {}

Grafo::~Grafo() {}

void Grafo::adicionarVertice(Vertice* v) {
    vertices.push_back(v);
}

void Grafo::adicionarAresta(Aresta* a) {
    arestas.push_back(a);
}

void Grafo::removerVertice(Vertice* v) {
    // Percorre a lista de arestas e remove as que estão conectadas ao vértice
    for (auto it = arestas.begin(); it != arestas.end();) {
        if ((*it)->getOrigem() == v || (*it)->getDestino() == v) {
            it = arestas.erase(it);
        } else {
            ++it;
        }
    }

    // Remove o vértice da lista de vértices
    for (auto it = vertices.begin(); it != vertices.end();) {
        if ((*it) == v) {
            it = vertices.erase(it);
        } else {
            ++it;
        }
    }
}

void Grafo::removerAresta(Aresta* a) {
    // Remove a aresta da lista de arestas
    for (auto it = arestas.begin(); it != arestas.end();) {
        if ((*it) == a) {
            it = arestas.erase(it);
        } else {
            ++it;
        }
    }
}

#include "Aresta.h"

Aresta::Aresta(Vertice* origem, Vertice* destino, int peso) :
    m_origem(origem), m_destino(destino), m_peso(peso)
{}

Vertice* Aresta::getOrigem() {
    return m_origem;
}

void Aresta::setOrigem(Vertice* origem) {
    m_origem = origem;
}

Vertice* Aresta::getDestino() {
    return m_destino;
}

void Aresta::setDestino(Vertice* destino) {
    m_destino = destino;
}

int Aresta::getPeso() {
    return m_peso;
}

void Aresta::setPeso(int peso) {
    m_peso = peso;
}

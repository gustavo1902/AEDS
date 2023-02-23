#include "Vertice.h"
#include "Aresta.h"

Vertice::Vertice(std::string nome, double posX, double posY) : nome(nome), posX(posX), posY(posY) {}

Vertice::~Vertice() {
    for (Aresta* aresta : arestasConectadas) {
        delete aresta;
    }
}

std::string Vertice::getNome() const {
    return nome;
}

double Vertice::getPosX() const {
    return posX;
}

double Vertice::getPosY() const {
    return posY;
}

std::vector<Aresta*> Vertice::getArestasConectadas() const {
    return arestasConectadas;
}

void Vertice::adicionarAresta(Aresta* aresta) {
    arestasConectadas.push_back(aresta);
}

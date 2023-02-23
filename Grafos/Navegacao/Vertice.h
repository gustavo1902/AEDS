#ifndef VERTICE_H
#define VERTICE_H

#include <string>
#include <vector>

class Aresta; // Forward declaration para evitar dependência circular

class Vertice {
private:
    std::string nome;
    double posX, posY;
    std::vector<Aresta*> arestasConectadas;

public:
    Vertice(std::string nome, double posX, double posY);
    ~Vertice();

    std::string getNome() const;
    double getPosX() const;
    double getPosY() const;
    std::vector<Aresta*> getArestasConectadas() const;
    void adicionarAresta(Aresta* aresta);
};

#endif // VERTICE_H

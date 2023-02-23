#include <iostream>
#include "Mapa.h"
#include "Dijkstra.h"

int main() {
    // Criar um mapa com 10x10 vértices
    Mapa mapa(10, 10);

    // Inserir vértices no mapa
    mapa.inserirVertice(0, 0);
    mapa.inserirVertice(1, 0);
    mapa.inserirVertice(2, 0);
    mapa.inserirVertice(2, 1);
    mapa.inserirVertice(2, 2);
    mapa.inserirVertice(3, 2);
    mapa.inserirVertice(4, 2);
    mapa.inserirVertice(4, 3);
    mapa.inserirVertice(4, 4);
    mapa.inserirVertice(3, 4);
    mapa.inserirVertice(2, 4);
    mapa.inserirVertice(1, 4);
    mapa.inserirVertice(0, 4);
    mapa.inserirVertice(0, 3);

    // Inserir arestas no mapa
    mapa.inserirAresta(0, 0, 1, 0, 1);
    mapa.inserirAresta(1, 0, 2, 0, 1);
    mapa.inserirAresta(2, 0, 2, 1, 1);
    mapa.inserirAresta(2, 1, 2, 2, 1);
    mapa.inserirAresta(2, 2, 3, 2, 1);
    mapa.inserirAresta(3, 2, 4, 2, 1);
    mapa.inserirAresta(4, 2, 4, 3, 1);
    mapa.inserirAresta(4, 3, 4, 4, 1);
    mapa.inserirAresta(4, 4, 3, 4, 1);
    mapa.inserirAresta(3, 4, 2, 4, 1);
    mapa.inserirAresta(2, 4, 1, 4, 1);
    mapa.inserirAresta(1, 4, 0, 4, 1);
    mapa.inserirAresta(0, 4, 0, 3, 1);
    mapa.inserirAresta(0, 3, 0, 0, 2);

    // Encontrar o caminho mais curto entre os vértices (0,0) e (4,4)
    Dijkstra dijkstra;
    std::vector<int> caminho = dijkstra.encontrarCaminho(mapa, 0, 0, 4, 4);

    // Imprimir o caminho mais curto
    std::cout << "Caminho mais curto: ";
    for (int i = 0; i < caminho.size(); i++) {
        std::cout << "(" << mapa.getVerticeX(caminho[i]) << "," << mapa.getVerticeY(caminho[i]) << ")";
        if (i != caminho.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;

    return 0;
}

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <queue>
#include "Grafo.h" // inclui a estrutura de dados do grafo

using namespace std;

class Dijkstra {
private:
    vector<int> dist; // vetor que armazena a menor distância do vértice de origem a cada vértice
    vector<int> ant;  // vetor que armazena o vértice anterior no caminho mais curto para cada vértice
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // fila de prioridade para implementar o algoritmo

public:
    Dijkstra();
    void executar(Grafo* grafo, int origem); // executa o algoritmo de Dijkstra a partir de um vértice de origem
    vector<int> getDistancias(); // retorna o vetor com as distâncias mínimas
    vector<int> getCaminho(int destino); // retorna o caminho mínimo entre a origem e um destino
};

#endif // DIJKSTRA_H

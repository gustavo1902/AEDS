#include "Dijkstra.h"

Dijkstra::Dijkstra() {}

void Dijkstra::executar(Grafo* grafo, int origem) {
    // Inicializa os vetores de distâncias e anteriores
    int tam = grafo->getNumVertices();
    dist.assign(tam, INT_MAX);
    ant.assign(tam, -1);

    // Define a distância da origem como 0
    dist[origem] = 0;

    // Insere a origem na fila de prioridade
    pq.push(make_pair(0, origem));

    // Executa o algoritmo de Dijkstra
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Percorre as arestas saindo do vértice u
        for (Aresta* a : grafo->getVertices()[u]->getArestas()) {
            int v = a->getDestino();
            int peso = a->getPeso();

            // Relaxamento da aresta
            if (dist[v] > dist[u] + peso) {
                dist[v] = dist[u] + peso;
                ant[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

vector<int> Dijkstra::getDistancias() {
    return dist;
}

vector<int> Dijkstra::getCaminho(int destino) {
    vector<int> caminho;
    caminho.push_back(destino);

    while (ant[destino] != -1) {
        destino = ant[destino];
        caminho.push_back(destino);
    }

    reverse(caminho.begin(), caminho.end());

    return caminho;
}

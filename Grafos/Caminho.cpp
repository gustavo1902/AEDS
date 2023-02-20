// O problema é o de encontrar o caminho mais curto entre
// dois vétices em um grafo, utilizando o algoritmo de Dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Definição da estrutura de uma aresta
struct Edge {
    int to;     // Vértice de destino da aresta
    int weight; // Peso da aresta
};

// Definição da estrutura de um nó
struct Node {
    int id;                 // Identificador do vértice
    int distance;           // Distância até o vértice fonte
    vector<Edge> neighbors; // Lista de arestas incidentes no vértice
};

// Função para encontrar o caminho mais curto entre dois vértices
void dijkstra(vector<Node>& graph, int source, int destination) {
    // Define a distância até todos os vértices como infinito, exceto o vértice fonte
    const int INF = numeric_limits<int>::max(); // Constante para representar infinito
    for (int i = 0; i < graph.size(); i++) {
        graph[i].distance = (i == source ? 0 : INF);
    }

    // Define a fila de prioridade para explorar os vértices
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    // Explora os vértices em ordem de distância até o vértice fonte
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (u == destination) {
            break;
        }
        for (int i = 0; i < graph[u].neighbors.size(); i++) {
            int v = graph[u].neighbors[i].to;
            int weight = graph[u].neighbors[i].weight;
            if (graph[u].distance + weight < graph[v].distance) {
                graph[v].distance = graph[u].distance + weight;
                pq.push(make_pair(graph[v].distance, v));
            }
        }
    }

    // Imprime a distância mínima até o vértice destino
    cout << "A menor distância de " << source << " a " << destination << " é " << graph[destination].distance << endl;
}

// Função principal
int main() {
    // Define o grafo como um vetor de nós
    vector<Node> graph(6);

    // Define as arestas do grafo
    graph[0].neighbors = { {1, 7}, {2, 9}, {5, 14} };
    graph[1].neighbors = { {0, 7}, {2, 10}, {3, 15} };
    graph[2].neighbors = { {0, 9}, {1, 10}, {3, 11}, {5, 2} };
    graph[3].neighbors = { {1, 15}, {2, 11}, {4, 6} };
    graph[4].neighbors = { {3, 6}, {5, 9} };
    graph[5].neighbors = { {0, 14}, {2, 2}, {4, 9} };

    // Encontra o caminho mais curto entre dois vértices
    dijkstra(graph, 0, 4);

    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Definição da estrutura para armazenar uma aresta
struct Aresta {
    int origem;
    int destino;
    int peso;
};

// Função para comparar duas arestas com base em seus pesos
bool compararArestas(Aresta a, Aresta b) {
    return a.peso < b.peso;
}

// Função para encontrar a componente conexa de um vértice
int encontrarComponenteConexa(int v, vector<int>& componentesConexas) {
    if (componentesConexas[v] == -1) {
        return v;
    } else {
        return encontrarComponenteConexa(componentesConexas[v], componentesConexas);
    }
}

// Função principal que implementa o algoritmo de Kruskal
vector<Aresta> kruskal(int nVertices, vector<Aresta>& arestas) {
    vector<int> componentesConexas(nVertices, -1);
    vector<Aresta> arvoreGeradoraMinima;

    // Ordena as arestas em ordem crescente de peso
    sort(arestas.begin(), arestas.end(), compararArestas);

    // Itera sobre todas as arestas, adicionando à árvore geradora mínima se não formar ciclo
    for (Aresta aresta : arestas) {
        int componenteConexaOrigem = encontrarComponenteConexa(aresta.origem, componentesConexas);
        int componenteConexaDestino = encontrarComponenteConexa(aresta.destino, componentesConexas);

        if (componenteConexaOrigem != componenteConexaDestino) {
            arvoreGeradoraMinima.push_back(aresta);
            componentesConexas[componenteConexaOrigem] = componenteConexaDestino;
        }
    }

    return arvoreGeradoraMinima;
}

// Exemplo de uso do algoritmo de Kruskal
int main() {
    int nVertices = 6;
    vector<Aresta> arestas = {{0, 1, 5}, {0, 2, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 2}, {2, 4, 6}, {3, 4, 7}};

    vector<Aresta> arvoreGeradoraMinima = kruskal(nVertices, arestas);

    for (Aresta aresta : arvoreGeradoraMinima) {
        cout << "(" << aresta.origem << "," << aresta.destino << ") = " << aresta.peso << endl;
    }

    return 0;
}

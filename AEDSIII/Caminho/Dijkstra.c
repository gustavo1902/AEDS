#include <stdio.h>
#include <stdbool.h>
#define INFINITY 9999

void dijkstra(int graph[100][100], int vertices, int source) {
    int distance[vertices];
    bool visited[vertices];

    for (int i = 0; i < vertices; i++) {
        distance[i] = INFINITY;
        visited[i] = false;
    }

    distance[source] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int minDistance = INFINITY, minVertex;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && distance[v] <= minDistance) {
                minDistance = distance[v];
                minVertex = v;
            }
        }

        int u = minVertex;
        visited[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INFINITY &&
                distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("Distâncias mínimas a partir do vértice %d:\n", source);
    for (int i = 0; i < vertices; i++) {
        printf("Vértice %d: %d\n", i, distance[i]);
    }
}

int main() {
    int vertices, edges;
    printf("Digite o número de vértices e arestas do grafo: ");
    scanf("%d %d", &vertices, &edges);

    int graph[100][100] = {0};

    printf("Digite as arestas e seus pesos:\n");
    for (int i = 0; i < edges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
    }

    int source;
    printf("Digite o vértice de origem para encontrar os caminhos mais curtos: ");
    scanf("%d", &source);

    dijkstra(graph, vertices, source);

    return 0;
}

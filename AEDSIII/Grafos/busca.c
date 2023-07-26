#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

// Estrutura para representar um grafo usando lista de adjacência
struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjList;
};

// Função para criar um novo nó na lista de adjacência
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo com N vértices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Função de busca em profundidade (DFS)
void DFS(struct Graph* graph, int v, int target, int visited[], int path[], int* found) {
    if (*found) {
        return;
    }
    visited[v] = 1;
    path[*found] = v;
    if (v == target) {
        *found = 1;
        return;
    }
    struct Node* temp = graph->adjList[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, target, visited, path, found);
        }
        temp = temp->next;
    }
}

// Função de busca em largura (BFS)
void BFS(struct Graph* graph, int v, int target, int visited[], int path[], int* found) {
    if (*found) {
        return;
    }
    int queue[MAX_VERTICES];
    int front = -1;
    int rear = -1;
    visited[v] = 1;
    queue[++rear] = v;
    while (front < rear) {
        v = queue[++front];
        path[*found] = v;
        if (v == target) {
            *found = 1;
            return;
        }
        struct Node* temp = graph->adjList[v];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int N, M;
    printf("Digite o número de vértices e arestas do grafo: ");
    scanf("%d %d", &N, &M);

    struct Graph* graph = createGraph(N);

    printf("Digite as arestas do grafo:\n");
    for (int i = 0; i < M; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int source, target;
    printf("Digite o vértice de origem e destino para encontrar o caminho: ");
    scanf("%d %d", &source, &target);

    int visited[MAX_VERTICES] = {0};
    int path[MAX_VERTICES] = {0};
    int found = 0;

    // Busca em profundidade
    printf("Caminho encontrado usando busca em profundidade:\n");
    DFS(graph, source, target, visited, path, &found);
    if (found) {
        for (int i = 0; i <= found; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        printf("Caminho não encontrado.\n");
    }

    // Reinicializa variáveis
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
        path[i] = 0;
    }
    found = 0;

    // Busca em largura
    printf("Caminho encontrado usando busca em largura:\n");
    BFS(graph, source, target, visited, path, &found);
    if (found) {
        for (int i = 0; i <= found; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        printf("Caminho não encontrado.\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

bool grafo[MAX_VERTICES][MAX_VERTICES];
int n; // Número de vértices do grafo

bool verificaCicloHamiltoniano(int v, bool visitados[MAX_VERTICES], int caminho[MAX_VERTICES], int pos) {
    if (pos == n) {
        if (grafo[caminho[pos - 1]][caminho[0]]) {
            return true; // Encontrou um ciclo hamiltoniano
        }
        return false;
    }

    for (int i = 0; i < n; i++) {
        if (grafo[caminho[pos - 1]][i] && !visitados[i]) {
            visitados[i] = true;
            caminho[pos] = i;

            if (verificaCicloHamiltoniano(v, visitados, caminho, pos + 1)) {
                return true;
            }

            visitados[i] = false;
        }
    }

    return false;
}

bool grafoHamiltoniano() {
    bool visitados[MAX_VERTICES];
    int caminho[MAX_VERTICES];

    for (int i = 0; i < n; i++) {
        visitados[i] = false;
    }

    caminho[0] = 0;
    visitados[0] = true;

    return verificaCicloHamiltoniano(0, visitados, caminho, 1);
}

int main() {
    // Lógica para leitura do grafo a partir de um arquivo ou entrada do usuário
    // O grafo pode ser representado como uma matriz de adjacências
    // O número de vértices (n) também deve ser definido

    if (grafoHamiltoniano()) {
        printf("O grafo é hamiltoniano.\n");
    } else {
        printf("O grafo não é hamiltoniano.\n");
    }

    return 0;
}

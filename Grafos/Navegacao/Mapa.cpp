#include "Mapa.h"
#include <iostream>

Mapa::Mapa(int tamanho) {
    this->tamanho = tamanho;
    this->matriz.resize(tamanho);
    for (int i = 0; i < tamanho; i++) {
        this->matriz[i].resize(tamanho);
        for (int j = 0; j < tamanho; j++) {
            this->matriz[i][j] = nullptr;
        }
    }
}

Mapa::~Mapa() {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (this->matriz[i][j] != nullptr) {
                delete this->matriz[i][j];
            }
        }
    }
}

void Mapa::inserirVertice(int linha, int coluna, std::string nome) {
    if (this->verificaPosicao(linha, coluna)) {
        if (this->matriz[linha][coluna] == nullptr) {
            Vertice* vertice = new Vertice(nome);
            this->matriz[linha][coluna] = vertice;
        } else {
            std::cout << "Posição já ocupada!" << std::endl;
        }
    } else {
        std::cout << "Posição inválida!" << std::endl;
    }
}

void Mapa::removerVertice(int linha, int coluna) {
    if (this->verificaPosicao(linha, coluna)) {
        if (this->matriz[linha][coluna] != nullptr) {
            delete this->matriz[linha][coluna];
            this->matriz[linha][coluna] = nullptr;
        } else {
            std::cout << "Posição vazia!" << std::endl;
        }
    } else {
        std::cout << "Posição inválida!" << std::endl;
    }
}

void Mapa::inserirAresta(int linha1, int coluna1, int linha2, int coluna2, int peso) {
    if (this->verificaPosicao(linha1, coluna1) && this->verificaPosicao(linha2, coluna2)) {
        if (this->matriz[linha1][coluna1] != nullptr && this->matriz[linha2][coluna2] != nullptr) {
            Vertice* origem = this->matriz[linha1][coluna1];
            Vertice* destino = this->matriz[linha2][coluna2];
            Aresta* aresta = new Aresta(peso,origem,destino);
            origem->adicionarAresta(aresta);
        }
    }
}

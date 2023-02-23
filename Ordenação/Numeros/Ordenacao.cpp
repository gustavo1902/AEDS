#include "Ordenacao.h"
#include <iostream>

void Ordenacao::inserirNumero(int numero) {
    listaNumeros.push_back(numero);
}

void Ordenacao::ordenarBubbleSort() {
    int tamanhoLista = listaNumeros.size();
    for (int i = 0; i < tamanhoLista - 1; i++) {
        for (int j = 0; j < tamanhoLista - i - 1; j++) {
            if (listaNumeros[j] > listaNumeros[j + 1]) {
                std::swap(listaNumeros[j], listaNumeros[j + 1]);
            }
        }
    }
}

void Ordenacao::ordenarSelectionSort() {
    int tamanhoLista = listaNumeros.size();
    for (int i = 0; i < tamanhoLista - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < tamanhoLista; j++) {
            if (listaNumeros[j] < listaNumeros[menor]) {
                menor = j;
            }
        }
        std::swap(listaNumeros[menor], listaNumeros[i]);
    }
}

void Ordenacao::ordenarInsertionSort() {
    int tamanhoLista = listaNumeros.size();
    for (int i = 1; i < tamanhoLista; i++) {
        int chave = listaNumeros[i];
        int j = i - 1;
        while (j >= 0 && listaNumeros[j] > chave) {
            listaNumeros[j + 1] = listaNumeros[j];
            j--;
        }
        listaNumeros[j + 1] = chave;
    }
}

void Ordenacao::ordenarQuickSort(int esquerda, int direita) {
    int i = esquerda;
    int j = direita;
    int pivo = listaNumeros[(esquerda + direita) / 2];
    while (i <= j) {
        while (listaNumeros[i] < pivo) {
            i++;
        }
        while (listaNumeros[j] > pivo) {
            j--;
        }
        if (i <= j) {
            std::swap(listaNumeros[i], listaNumeros[j]);
            i++;
            j--;
        }
    }
    if (esquerda < j) {
        ordenarQuickSort(esquerda, j);
    }
    if (i < direita) {
        ordenarQuickSort(i, direita);
    }
}

void Ordenacao::imprimirLista() {
    for (int numero : listaNumeros) {
        std::cout << numero << " ";
    }
    std::cout << std::endl;
}

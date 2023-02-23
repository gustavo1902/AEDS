#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <vector>

class Ordenacao {
private:
    std::vector<int> listaNumeros;

public:
    void inserirNumero(int numero);
    void ordenarBubbleSort();
    void ordenarSelectionSort();
    void ordenarInsertionSort();
    void ordenarQuickSort(int esquerda, int direita);
    void imprimirLista();
};

#endif

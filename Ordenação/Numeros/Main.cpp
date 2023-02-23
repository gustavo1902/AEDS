#include <iostream>
#include <vector>
#include "Ordenacao.h"

using namespace std;

int main() {
    // Exemplo de vetor de números a ser ordenado
    vector<int> numeros = {5, 2, 9, 1, 8, 3, 7, 4, 6};

    // Criação do objeto Ordenacao
    Ordenacao ordenacao;

    // Exibição da lista de números original
    cout << "Lista de numeros original: ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    // Escolha do algoritmo de ordenação e exibição da lista ordenada
    int opcao;
    cout << "Escolha o algoritmo de ordenacao: " << endl;
    cout << "1 - Bubble Sort" << endl;
    cout << "2 - Insertion Sort" << endl;
    cout << "3 - Selection Sort" << endl;
    cout << "4 - Merge Sort" << endl;
    cout << "5 - Quick Sort" << endl;
    cout << "Opcao: ";
    cin >> opcao;

    switch (opcao) {
        case 1:
            ordenacao.bubbleSort(numeros);
            cout << "Lista de numeros ordenada por Bubble Sort: ";
            break;
        case 2:
            ordenacao.insertionSort(numeros);
            cout << "Lista de numeros ordenada por Insertion Sort: ";
            break;
        case 3:
            ordenacao.selectionSort(numeros);
            cout << "Lista de numeros ordenada por Selection Sort: ";
            break;
        case 4:
            ordenacao.mergeSort(numeros);
            cout << "Lista de numeros ordenada por Merge Sort: ";
            break;
        case 5:
            ordenacao.quickSort(numeros);
            cout << "Lista de numeros ordenada por Quick Sort: ";
            break;
        default:
            cout << "Opcao invalida." << endl;
            return 1;
    }

    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

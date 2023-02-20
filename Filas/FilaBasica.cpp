#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> fila; // Declara uma fila de inteiros vazia

    // Insere elementos na fila
    fila.push(1);
    fila.push(2);
    fila.push(3);

    // Imprime o tamanho da fila
    cout << "Tamanho da fila: " << fila.size() << endl;

    // Acessa o elemento da frente da fila (sem removê-lo)
    cout << "Elemento da frente: " << fila.front() << endl;

    // Remove o elemento da frente da fila
    fila.pop();

    // Imprime o tamanho da fila novamente
    cout << "Tamanho da fila: " << fila.size() << endl;

    // Insere mais elementos na fila
    fila.push(4);
    fila.push(5);

    // Remove todos os elementos da fila e os imprime
    while (!fila.empty()) {
        cout << "Elemento removido: " << fila.front() << endl;
        fila.pop();
    }

    return 0;
}

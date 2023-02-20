#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> pilha; // Declara uma pilha de inteiros vazia

    // Insere elementos na pilha
    pilha.push(1);
    pilha.push(2);
    pilha.push(3);

    // Imprime o tamanho da pilha
    cout << "Tamanho da pilha: " << pilha.size() << endl;

    // Acessa o elemento do topo da pilha (sem removê-lo)
    cout << "Elemento do topo: " << pilha.top() << endl;

    // Remove o elemento do topo da pilha
    pilha.pop();

    // Imprime o tamanho da pilha novamente
    cout << "Tamanho da pilha: " << pilha.size() << endl;

    // Insere mais elementos na pilha
    pilha.push(4);
    pilha.push(5);

    // Remove todos os elementos da pilha e os imprime
    while (!pilha.empty()) {
        cout << "Elemento removido: " << pilha.top() << endl;
        pilha.pop();
    }

    return 0;
}

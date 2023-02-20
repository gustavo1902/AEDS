#include <iostream>

using namespace std;

// Definição da estrutura do nó
struct Node {
    int data;   // Dado armazenado no nó
    Node* prev; // Ponteiro para o nó anterior na lista
    Node* next; // Ponteiro para o próximo nó na lista
};

// Função para adicionar um novo nó no início da lista
void insertAtBeginning(Node*& head, int newData) {
    // Aloca um novo nó e define seus dados
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = head;
    // Define o novo nó como a cabeça da lista
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// Função para imprimir a lista
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Função principal
int main() {
    // Inicializa a lista como vazia
    Node* head = NULL;
    // Insere alguns elementos no início da lista
    insertAtBeginning(head, 1);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 3);
    // Imprime a lista
    printList(head);
    return 0;
}

#include <iostream>
#include <unordered_map>

using namespace std;

// Estrutura do nó da árvore hash
struct Node {
    int data;
    unordered_map<int, Node*> children;
};

// Função para criar um novo nó
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    return node;
}

// Função para inserir um dado na árvore hash
void insert(Node* root, int data) {
    Node* node = newNode(data);
    root->children[data] = node;
}

// Função para procurar um dado na árvore hash
bool search(Node* root, int data) {
    if (root->children.count(data) > 0)
        return true;
    return false;
}

int main() {
    // Criando a raiz da árvore hash
    Node* root = newNode(-1);

    // Inserindo alguns dados na árvore hash
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);

    // Procurando um dado na árvore hash
    int data = 20;
    if (search(root, data))
        cout << "O dado " << data << " foi encontrado na árvore hash." << endl;
    else
        cout << "O dado " << data << " não foi encontrado na árvore hash." << endl;

    return 0;
}

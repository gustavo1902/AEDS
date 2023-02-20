#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Estrutura do nó da árvore
struct Node {
    int data;
    Node *left, *right;
};

// Função para alocar um novo nó
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Função para inserir um dado na árvore
Node* insert(Node* root, int data) {
    if (!root)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Função para ler dados do arquivo e inserir na árvore
Node* readFile(const char* filename) {
    Node* root = NULL;
    vector<int> data;
    int value;

    // Abrir o arquivo
    ifstream file(filename);

    // Verificar se o arquivo foi aberto com sucesso
    if (file.is_open()) {
        // Lendo dados do arquivo e adicionando ao vetor
        while (file >> value)
            data.push_back(value);

        // Fechar o arquivo
        file.close();

        // Inserindo os dados no vetor na árvore
        for (int i = 0; i < data.size(); i++)
            root = insert(root, data[i]);
    } else {
        cout << "Erro ao abrir o arquivo" << endl;
    }

    return root;
}

int main() {
    Node* root = readFile("file.txt");
    return 0;
}

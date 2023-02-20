#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Estrutura do nó da árvore heap
struct Node
{
    int data;
    int index;
    Node *left, *right;
};

// Função para alocar um novo nó
Node *newNode(int data, int index)
{
    Node *node = new Node;
    node->data = data;
    node->index = index;
    node->left = node->right = NULL;
    return node;
}

// Função para corrigir a propriedade de heap
void heapify(vector<Node *> &heap, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() && heap[left]->data > heap[largest]->data)
        largest = left;

    if (right < heap.size() && heap[right]->data > heap[largest]->data)
        largest = right;

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapify(heap, largest);
    }
}

// Função para construir a árvore heap
void buildHeap(vector<Node *> &heap)
{
    int n = heap.size();
    int startIndex = (n / 2) - 1;

    for (int i = startIndex; i >= 0; i--)
        heapify(heap, i);
}

// Função para inserir um dado na árvore heap
void insert(vector<Node *> &heap, int data, int &index)
{
    Node *node = newNode(data, index);
    heap.push_back(node);

    int i = heap.size() - 1;
    while (i && heap[(i - 1) / 2]->data < heap[i]->data)
    {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }

    index++;
}

// Função para ler dados do arquivo e inserir na árvore heap
void readFile(const char *filename, vector<Node *> &heap)
{
    int value, index = 0;

    // Abrir o arquivo
    ifstream file(filename);

    // Verificar se o arquivo foi aberto com sucesso
    if (file.is_open())
    {
        // Lendo dados do arquivo e adicionando ao vetor
        while (file >> value)
            insert(heap, value, index);

        // Fechar o arquivo
        file.close();

        // Construir a árvore heap a partir do vetor
        buildHeap(heap);
    }
    else
    {
        cout << "Não foi possível abrir o arquivo: " << filename << endl;
    }
}

// Função para imprimir a árvore heap
void printHeap(vector<Node *> &heap)
{
    cout << "Árvore Heap: [ ";
    for (int i = 0; i < heap.size(); i++)
        cout << heap[i]->data << " ";
    cout << "]" << endl;
}

int main(int argc, char *argv[])
{
    vector<Node *> heap;

    // Verificar se o nome do arquivo foi passado como argumento
    if (argc != 2)
    {
        cout << "Uso: " << argv[0] << " <nome_do_arquivo>" << endl;
        return 1;
    }

    // Ler dados do arquivo e criar a árvore heap
    readFile(argv[1], heap);

    // Imprimir a árvore heap
    printHeap(heap);

    return 0;
}


/*
colocar do menor para o maior
// Função para corrigir a propriedade de heap
void heapify(vector<Node*> &heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() && heap[left]->data < heap[smallest]->data)
        smallest = left;

    if (right < heap.size() && heap[right]->data < heap[smallest]->data)
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, smallest);
    }
}

// Função para inserir um dado na árvore heap
void insert(vector<Node*> &heap, int data, int &index) {
    Node* node = newNode(data, index);
    heap.push_back(node);

    int i = heap.size() - 1;
    while (i && heap[(i - 1) / 2]->data > heap[i]->data) {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }

    index++;
}
*/
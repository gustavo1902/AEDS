#include <iostream>
#include <fstream>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* newNode(int data)
{
    node* temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* root, int data)
{
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void readFile(node* &root, string fileName)
{
    ifstream file(fileName);
    int data;
    while (file >> data)
    {
        root = insert(root, data);
    }
    file.close();
}

int main()
{
    node* root = NULL;
    string fileName = "valores.txt";

    readFile(root, fileName);

    cout << "Arvore binaria de busca " << fileName << endl;

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* frente = NULL;
struct Node* tras = NULL;

int isEmpty() {
    return (frente == NULL);
}

void enqueue(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty()) {
        frente = newNode;
        tras = newNode;
    } else {
        tras->next = newNode;
        tras = newNode;
    }
    printf("Elemento %d inserido na fila.\n", data);
}

int dequeue() {
    if (isEmpty()) {
        printf("A fila está vazia. Não é possível remover elementos.\n");
        return -1;
    } else {
        struct Node* temp = frente;
        int data = frente->data;
        frente = frente->next;
        free(temp);
        return data;
    }
}

void display() {
    if (isEmpty()) {
        printf("A fila está vazia.\n");
    } else {
        struct Node* current = frente;
        printf("Fila: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();

    int removedElement = dequeue();
    printf("Elemento removido: %d\n", removedElement);

    enqueue(4);
    enqueue(5);
    enqueue(6);

    display();
    return 0;
}

#include <stdio.h>

#define MAX_SIZE 5

int fila[MAX_SIZE];
int frente = -1;
int tras = -1;

int isFull() {
    return (tras == MAX_SIZE - 1);
}

int isEmpty() {
    return (frente == -1 || frente > tras);
}

void enqueue(int data) {
    if (isFull()) {
        printf("A fila está cheia. Não é possível inserir o elemento %d.\n", data);
    } else {
        if (frente == -1) {
            frente = 0;
        }
        tras++;
        fila[tras] = data;
        printf("Elemento %d inserido na fila.\n", data);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("A fila está vazia. Não é possível remover elementos.\n");
        return -1;
    } else {
        int data = fila[frente];
        frente++;
        return data;
    }
}

void display() {
    if (isEmpty()) {
        printf("A fila está vazia.\n");
    } else {
        printf("Fila: ");
        for (int i = frente; i <= tras; i++) {
            printf("%d ", fila[i]);
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
    enqueue(6); // Tentando adicionar mais elementos do que o tamanho máximo da fila

    display();
    return 0;
}

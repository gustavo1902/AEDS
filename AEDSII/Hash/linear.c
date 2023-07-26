#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 10

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insertLinear(int table[], int key) {
    int index = hashFunction(key);

    while (table[index] != -1) {
        index = (index + 1) % TABLE_SIZE; // Próximo índice linearmente
    }

    table[index] = key;
}

bool searchLinear(int table[], int key) {
    int index = hashFunction(key);

    while (table[index] != key) {
        if (table[index] == -1) {
            return false; // Elemento não encontrado
        }
        index = (index + 1) % TABLE_SIZE; // Próximo índice linearmente
    }

    return true;
}

int main() {
    int table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = -1; // Inicializa a tabela com -1 (representando posição vazia)
    }

    insertLinear(table, 123);
    insertLinear(table, 456);
    insertLinear(table, 789);

    printf("Elemento 123 encontrado? %s\n", searchLinear(table, 123) ? "Sim" : "Não");
    printf("Elemento 999 encontrado? %s\n", searchLinear(table, 999) ? "Sim" : "Não");

    return 0;
}

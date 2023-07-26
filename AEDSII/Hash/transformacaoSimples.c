#include <stdio.h>

// Função de transformação usando operação de módulo
int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

int main() {
    int key = 123;
    int tableSize = 10;

    int index = hashFunction(key, tableSize);

    printf("Chave: %d\n", key);
    printf("Índice usando Hashing Funções de Transformação: %d\n", index);

    return 0;
}

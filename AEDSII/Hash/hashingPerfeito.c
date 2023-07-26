#include <stdio.h>

#define TABLE_SIZE 10

int hashFunction(int key) {
    return (key * 3) % TABLE_SIZE; // Exemplo de função de transformação simples
}

int main() {
    int key = 123;

    int index = hashFunction(key);

    printf("Chave: %d\n", key);
    printf("Índice usando Hashing Perfeito: %d\n", index);

    return 0;
}

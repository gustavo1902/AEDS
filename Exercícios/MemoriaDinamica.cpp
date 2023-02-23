#include <iostream>

int main() {
    int* ptr;

    // Alocação de memória dinâmica
    ptr = new int[5];

    // Atribuindo valores ao array
    for (int i = 0; i < 5; i++) {
        ptr[i] = i + 1;
    }

    // Imprimindo os valores do array
    for (int i = 0; i < 5; i++) {
        std::cout << "ptr[" << i << "] = " << ptr[i] << std::endl;
    }

    // Liberando a memória alocada
    delete[] ptr;

    return 0;
}

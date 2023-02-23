#include <iostream>

int main() {
    // Declarando um ponteiro nulo
    int* ptr = nullptr;

    // Verificando se o ponteiro é nulo
    if (ptr == nullptr) {
        std::cout << "O ponteiro é nulo!" << std::endl;
    }

    // Atribuindo um endereço de memória ao ponteiro
    int x = 10;
    ptr = &x;

    // Verificando se o ponteiro não é mais nulo
    if (ptr != nullptr) {
        std::cout << "O ponteiro não é mais nulo!" << std::endl;
    }

    return 0;
}

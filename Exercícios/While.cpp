#include <iostream>

int main() {
    int numero;

    do {
        std::cout << "Digite um número entre 1 e 10: ";
        std::cin >> numero;
    } while (numero < 1 || numero > 10);

    std::cout << "Você digitou o número " << numero << std::endl;

    return 0;
}

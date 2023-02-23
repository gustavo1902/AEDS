#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Declarando um vector de inteiros
    std::vector<int> numeros(5);

    // Preenchendo o vector com o valor 10 usando a função fill
    std::fill(numeros.begin(), numeros.end(), 10);

    // Imprimindo o vector
    std::cout << "Vector preenchido com o valor 10:" << std::endl;
    for (int numero : numeros) {
        std::cout << numero << " ";
    }
    std::cout << std::endl;

    return 0;
}

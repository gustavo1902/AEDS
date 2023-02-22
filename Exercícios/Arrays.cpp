#include <iostream>

int main() {
    // Declarando um array de inteiros com 5 elementos
    int numeros[5];

    // Atribuindo valores para cada elemento do array
    numeros[0] = 1;
    numeros[1] = 2;
    numeros[2] = 3;
    numeros[3] = 4;
    numeros[4] = 5;

    // Imprimindo o conteúdo do array
    std::cout << "O conteúdo do array é: ";
    for (int i = 0; i < 5; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;

    // Declarando e inicializando um array de strings
    std::string frutas[3] = {"maçã", "banana", "laranja"};

    // Imprimindo o conteúdo do array
    std::cout << "O conteúdo do array é: ";
    for (int i = 0; i < 3; i++) {
        std::cout << frutas[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
            
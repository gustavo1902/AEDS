#include <iostream>

int main() {
    // Declarando uma variável inteira e um ponteiro para essa variável
    int x = 10;
    int* ptr = &x;

    // Imprimindo o valor da variável e do ponteiro
    std::cout << "Valor de x: " << x << std::endl;
    std::cout << "Endereço de memória de x: " << &x << std::endl;
    std::cout << "Valor de ptr: " << ptr << std::endl;
    std::cout << "Valor apontado por ptr: " << *ptr << std::endl;

    // Modificando o valor de x através do ponteiro
    *ptr = 20;

    // Imprimindo o novo valor de x
    std::cout << "Novo valor de x: " << x << std::endl;

    return 0;
}

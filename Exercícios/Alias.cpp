//Aliases e typedefs

#include <iostream>

typedef int inteiro; // definindo um typedef para int
using pontoFlutuante = float; // definindo um alias para float

int main() {
    inteiro numeroInteiro = 10;
    pontoFlutuante numeroReal = 3.1415f;

    std::cout << "Numero inteiro: " << numeroInteiro << std::endl;
    std::cout << "Numero real: " << numeroReal << std::endl;

    return 0;
}


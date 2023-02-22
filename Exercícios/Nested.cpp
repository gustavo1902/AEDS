#include <iostream>

int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 3; j++) {
            std::cout << i << " " << j << std::endl;
        }
    }

    return 0;
}
/*
Nesse código, há dois loops for aninhados (nested loops). 
O primeiro loop for é executado 5 vezes, e o segundo loop for é executado 3 vezes 
para cada iteração do primeiro loop. Dentro do segundo loop for, é impresso na tela 
os valores de "i" e "j" usando "std::cout". 
Como resultado, são impressos 15 pares de valores na tela,
representando todas as combinações possíveis de valores de "i" e "j".
*/
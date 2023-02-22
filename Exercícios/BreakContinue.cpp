#include <iostream>

int main() {
    // Exemplo de uso do break
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            break; // o loop é interrompido quando i = 5
        }
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Exemplo de uso do continue
    for (int j = 1; j <= 10; j++) {
        if (j == 5) {
            continue; // o loop pula a iteração quando j = 5
        }
        std::cout << j << " ";
    }
    std::cout << std::endl;

    return 0;
}

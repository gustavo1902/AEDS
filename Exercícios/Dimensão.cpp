#include <iostream>

int main() {
    // Declarando uma matriz de inteiros de 2 dimensões (2 x 3)
    int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // Imprimindo a matriz
    std::cout << "Matriz de inteiros de 2 dimensões:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

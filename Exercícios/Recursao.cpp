#include <iostream>

int fatorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

int main() {
    int num;

    std::cout << "Digite um número inteiro positivo: ";
    std::cin >> num;

    std::cout << num << "! = " << fatorial(num) << std::endl;

    return 0;
}

#include <iostream>
#include <string>

struct Pessoa {
    std::string nome;
    int idade;
    double altura;
};

int main() {
    Pessoa p1 = {"Gustavo", 25, 1.78};
    Pessoa p2 = {"Maria", 30, 1.65};

    std::cout << p1.nome << " tem " << p1.idade << " anos e mede " << p1.altura << "m de altura." << std::endl;
    std::cout << p2.nome << " tem " << p2.idade << " anos e mede " << p2.altura << "m de altura." << std::endl;

    return 0;
}

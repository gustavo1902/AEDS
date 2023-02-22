#include <iostream>

int main(){
    std::string nome;
    while(nome.empty()){
        std::cout << "Qual seu nome: ";
        std::getline(std::cin, nome);
    }
    std::cout << "Olá" << nome;
    return 0;
}
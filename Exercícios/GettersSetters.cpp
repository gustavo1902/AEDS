#include <iostream>
#include <string>

class Pessoa {
private:
    std::string nome;
    int idade;
public:
    std::string getNome() const {
        return nome;
    }

    void setNome(const std::string& novoNome) {
        nome = novoNome;
    }

    int getIdade() const {
        return idade;
    }

    void setIdade(int novaIdade) {
        idade = novaIdade;
    }
};

int main() {
    Pessoa p1;
    p1.setNome("Gustavo");
    p1.setIdade(25);

    std::cout << p1.getNome() << " tem " << p1.getIdade() << " anos." << std::endl;

    return 0;
}

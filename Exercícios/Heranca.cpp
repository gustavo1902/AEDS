#include <iostream>
using namespace std;

// Classe base
class Animal {
public:
    void comer() {
        cout << "Comendo...\n";
    }
};

// Classe derivada (herda da classe base Animal)
class Cachorro : public Animal {
public:
    void latir() {
        cout << "Au Au!\n";
    }
};

// Função principal
int main() {
    // Instanciação de um objeto da classe derivada Cachorro
    Cachorro c;

    // Chamada do método comer() da classe base através do objeto da classe derivada
    c.comer();

    // Chamada do método latir() da classe derivada através do objeto da classe derivada
    c.latir();

    return 0;
}

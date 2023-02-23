#ifndef NO_H
#define NO_H

#include <string>

class No {
public:
    // Construtor
    No(std::string nome, bool eh_diretorio);

    // Getters
    std::string get_nome();
    bool get_eh_diretorio();
    No* get_pai();
    No* get_filho_esquerda();
    No* get_filho_direita();

    // Setters
    void set_pai(No* pai);
    void set_filho_esquerda(No* filho);
    void set_filho_direita(No* filho);

private:
    std::string nome;
    bool eh_diretorio;
    No* pai;
    No* filho_esquerda;
    No* filho_direita;
};

#endif

#include "no.h"

// Construtor
No::No(std::string nome, bool eh_diretorio) {
    this->nome = nome;
    this->eh_diretorio = eh_diretorio;
    this->pai = nullptr;
    this->filho_esquerda = nullptr;
    this->filho_direita = nullptr;
}

// Getters
std::string No::get_nome() {
    return this->nome;
}

bool No::get_eh_diretorio() {
    return this->eh_diretorio;
}

No* No::get_pai() {
    return this->pai;
}

No* No::get_filho_esquerda() {
    return this->filho_esquerda;
}

No* No::get_filho_direita() {
    return this->filho_direita;
}

// Setters
void No::set_pai(No* pai) {
    this->pai = pai;
}

void No::set_filho_esquerda(No* filho) {
    this->filho_esquerda = filho;
}

void No::set_filho_direita(No* filho) {
    this->filho_direita = filho;
}

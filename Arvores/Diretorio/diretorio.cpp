#include "diretorio.h"
#include <iostream>

Diretorio::Diretorio(std::string nome) : Arquivo(nome, 0, "Diretório") {}

void Diretorio::adicionarArquivo(Arquivo* arquivo) {
    arquivos.push_back(arquivo);
}

void Diretorio::removerArquivo(std::string nome) {
    for (unsigned int i = 0; i < arquivos.size(); i++) {
        if (arquivos[i]->getNome() == nome) {
            delete arquivos[i];
            arquivos.erase(arquivos.begin() + i);
            return;
        }
    }
    std::cout << "Arquivo não encontrado.\n";
}

void Diretorio::listarArquivos() {
    std::cout << "Arquivos no diretório \"" << nome << "\":\n";
    for (unsigned int i = 0; i < arquivos.size(); i++) {
        std::cout << arquivos[i]->getNome() << " - " << arquivos[i]->getTipo() << "\n";
    }
}

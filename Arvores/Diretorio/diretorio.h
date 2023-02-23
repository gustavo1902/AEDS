#ifndef DIRETORIO_H
#define DIRETORIO_H

#include <string>
#include <vector>
#include "arquivo.h"

class Diretorio : public Arquivo {
    private:
        std::vector<Arquivo*> arquivos;

    public:
        Diretorio(std::string nome);

        void adicionarArquivo(Arquivo* arquivo);
        void removerArquivo(std::string nome);
        void listarArquivos();
};

#endif // DIRETORIO_H

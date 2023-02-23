#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>
#include <ctime>

class Arquivo {
    private:
        std::string nome;
        int tamanho;
        std::time_t dataCriacao;
        std::time_t dataModificacao;
        
    public:
        Arquivo(std::string nomeArquivo, int tamanhoArquivo, std::time_t dataCriacaoArquivo, std::time_t dataModificacaoArquivo);
        
        std::string getNome();
        int getTamanho();
        std::time_t getDataCriacao();
        std::time_t getDataModificacao();
        
        void setNome(std::string novoNome);
        void setTamanho(int novoTamanho);
        void setDataCriacao(std::time_t novaDataCriacao);
        void setDataModificacao(std::time_t novaDataModificacao);
};

#endif

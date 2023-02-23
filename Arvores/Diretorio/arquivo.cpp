#include "arquivo.h"

Arquivo::Arquivo(std::string nomeArquivo, int tamanhoArquivo, std::time_t dataCriacaoArquivo, std::time_t dataModificacaoArquivo) {
    nome = nomeArquivo;
    tamanho = tamanhoArquivo;
    dataCriacao = dataCriacaoArquivo;
    dataModificacao = dataModificacaoArquivo;
}

std::string Arquivo::getNome() {
    return nome;
}

int Arquivo::getTamanho() {
    return tamanho;
}

std::time_t Arquivo::getDataCriacao() {
    return dataCriacao;
}

std::time_t Arquivo::getDataModificacao() {
    return dataModificacao;
}

void Arquivo::setNome(std::string novoNome) {
    nome = novoNome;
}

void Arquivo::setTamanho(int novoTamanho) {
    tamanho = novoTamanho;
}

void Arquivo::setDataCriacao(std::time_t novaDataCriacao) {
    dataCriacao = novaDataCriacao;
}

void Arquivo::setDataModificacao(std::time_t novaDataModificacao) {
    dataModificacao = novaDataModificacao;
}

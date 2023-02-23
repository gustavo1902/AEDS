#include "arquivo.h"
#include "diretorio.h"
#include "arvore.h"
#include <iostream>
#include <string>

int main() {
    Arvore arvore;
    Diretorio *dirAtual = arvore.getRaiz(); // define o diretório atual como a raiz da árvore

    // Loop principal para interação com o usuário
    while (true) {
        std::cout << "Diretorio atual: " << dirAtual->getNome() << std::endl;
        std::cout << "1. Listar arquivos e diretorios" << std::endl;
        std::cout << "2. Criar arquivo" << std::endl;
        std::cout << "3. Criar diretorio" << std::endl;
        std::cout << "4. Mudar para diretorio" << std::endl;
        std::cout << "5. Voltar para diretorio anterior" << std::endl;
        std::cout << "6. Sair" << std::endl;
        std::cout << "Escolha uma opcao: ";

        int opcao;
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                std::cout << "Arquivos e diretorios:" << std::endl;
                dirAtual->listarConteudo();
                break;
            case 2: {
                std::string nomeArquivo;
                std::cout << "Digite o nome do arquivo: ";
                std::cin >> nomeArquivo;

                int tamanho;
                std::cout << "Digite o tamanho do arquivo: ";
                std::cin >> tamanho;

                Arquivo *novoArquivo = new Arquivo(nomeArquivo, tamanho);
                dirAtual->adicionarArquivo(novoArquivo);
                break;
            }
            case 3: {
                std::string nomeDiretorio;
                std::cout << "Digite o nome do diretorio: ";
                std::cin >> nomeDiretorio;

                Diretorio *novoDiretorio = new Diretorio(nomeDiretorio);
                dirAtual->adicionarDiretorio(novoDiretorio);
                break;
            }
            case 4: {
                std::string nomeDiretorio;
                std::cout << "Digite o nome do diretorio: ";
                std::cin >> nomeDiretorio;

                Diretorio *novoDir = dirAtual->buscarDiretorio(nomeDiretorio);
                if (novoDir != nullptr) {
                    dirAtual = novoDir;
                } else {
                    std::cout << "Diretorio nao encontrado" << std::endl;
                }
                break;
            }
            case 5:
                if (dirAtual->getPai() != nullptr) {
                    dirAtual = dirAtual->getPai();
                }
                break;
            case 6:
                return 0;
            default:
                std::cout << "Opcao invalida" << std::endl;
        }
    }

    return 0;
}

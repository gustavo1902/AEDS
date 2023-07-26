#include <stdio.h>
#include <stdlib.h>

void dividirArquivo(char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int blockSize = 4096; // Tamanho do bloco em bytes
    int blockNum = 1;
    char buffer[blockSize];

    while (!feof(arquivo)) {
        size_t bytesRead = fread(buffer, sizeof(char), blockSize, arquivo);
        if (bytesRead > 0) {
            char nomeBloco[20];
            sprintf(nomeBloco, "bloco_%d.txt", blockNum);
            FILE* bloco = fopen(nomeBloco, "w");
            fwrite(buffer, sizeof(char), bytesRead, bloco);
            fclose(bloco);
            blockNum++;
        }
    }

    fclose(arquivo);
}

int main() {
    char nomeArquivo[] = "arquivo_grande.txt";
    dividirArquivo(nomeArquivo);

    printf("Arquivo dividido em blocos com sucesso.\n");

    return 0;
}

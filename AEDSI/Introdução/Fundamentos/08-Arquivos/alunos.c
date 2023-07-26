#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100

int main() {
    FILE *arquivoTexto, *arquivoBinario;
    char nome[MAX_ALUNOS][100];
    int numeroAlunos = 0;

    // Abrir arquivo texto para leitura
    arquivoTexto = fopen("alunos.txt", "r");
    if (arquivoTexto == NULL) {
        printf("Erro ao abrir o arquivo alunos.txt.\n");
        exit(1);
    }

    // Ler os nomes dos alunos do arquivo texto
    while (fgets(nome[numeroAlunos], sizeof(nome[numeroAlunos]), arquivoTexto) != NULL) {
        // Remover o caractere de nova linha (\n) do final do nome
        nome[numeroAlunos][strcspn(nome[numeroAlunos], "\n")] = '\0';
        numeroAlunos++;
    }

    // Fechar o arquivo texto
    fclose(arquivoTexto);

    // Ordenar os nomes dos alunos em ordem alfabética
    for (int i = 0; i < numeroAlunos - 1; i++) {
        for (int j = i + 1; j < numeroAlunos; j++) {
            if (strcmp(nome[i], nome[j]) > 0) {
                char temp[100];
                strcpy(temp, nome[i]);
                strcpy(nome[i], nome[j]);
                strcpy(nome[j], temp);
            }
        }
    }

    // Abrir arquivo binário para escrita
    arquivoBinario = fopen("alunos.bin", "wb");
    if (arquivoBinario == NULL) {
        printf("Erro ao abrir o arquivo alunos.bin.\n");
        exit(1);
    }

    // Escrever os nomes dos alunos ordenados no arquivo binário
    fwrite(&numeroAlunos, sizeof(int), 1, arquivoBinario); // Escrever o número total de alunos no início do arquivo
    for (int i = 0; i < numeroAlunos; i++) {
        fwrite(nome[i], sizeof(char), strlen(nome[i]) + 1, arquivoBinario); // Escrever cada nome com o caractere nulo '\0' no final
    }

    // Fechar o arquivo binário
    fclose(arquivoBinario);

    printf("Total de alunos lidos: %d\n", numeroAlunos);

    return 0;
}

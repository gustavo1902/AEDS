#include <stdio.h>
#include <stdlib.h>

// Função para intercalar duas fitas
void merge(FILE* f1, FILE* f2, FILE* output) {
    int num1, num2;
    int endOfFile1 = fscanf(f1, "%d", &num1);
    int endOfFile2 = fscanf(f2, "%d", &num2);

    while (endOfFile1 != EOF && endOfFile2 != EOF) {
        if (num1 <= num2) {
            fprintf(output, "%d ", num1);
            endOfFile1 = fscanf(f1, "%d", &num1);
        } else {
            fprintf(output, "%d ", num2);
            endOfFile2 = fscanf(f2, "%d", &num2);
        }
    }

    // Escrever o restante dos elementos, se houver, em f1 e f2
    while (endOfFile1 != EOF) {
        fprintf(output, "%d ", num1);
        endOfFile1 = fscanf(f1, "%d", &num1);
    }
    while (endOfFile2 != EOF) {
        fprintf(output, "%d ", num2);
        endOfFile2 = fscanf(f2, "%d", &num2);
    }
}

// Função para dividir a fita em várias subfitas ordenadas
void divide(FILE* input, int chunkSize) {
    int num;
    int count = 0;
    FILE* output = NULL;

    while (fscanf(input, "%d", &num) != EOF) {
        if (count == 0) {
            char filename[20];
            sprintf(filename, "subfita%d.txt", count / chunkSize);
            output = fopen(filename, "w");
        }

        fprintf(output, "%d ", num);
        count++;

        if (count == chunkSize) {
            fclose(output);
            count = 0;
        }
    }

    if (count > 0) {
        fclose(output);
    }
}

// Função para ordenar externamente as subfitas
void externalSort(FILE* input, FILE* output, int chunkSize) {
    int subfitaCount = 0;
    char filename[20];

    // Dividir a fita em subfitas ordenadas
    divide(input, chunkSize);

    // Fundir as subfitas em uma única fita ordenada
    while (subfitaCount < 2) {
        sprintf(filename, "subfita%d.txt", subfitaCount);
        FILE* subfita = fopen(filename, "r");
        subfitaCount++;

        if (subfitaCount == 1) {
            // Primeira subfita é f1, a segunda é f2
            FILE* f1 = subfita;
            FILE* f2 = fopen("subfita1.txt", "r");
            merge(f1, f2, output);
            fclose(f2);
        } else {
            // f1 é a fita de saída, a segunda subfita é f2
            FILE* f1 = output;
            FILE* f2 = subfita;
            sprintf(filename, "subfita%d.txt", subfitaCount);
            output = fopen(filename, "w");
            merge(f1, f2, output);
            fclose(f2);
        }

        fclose(subfita);
    }
}

int main() {
    // Suponha que os dados a serem ordenados estão em "dados.txt"
    FILE* input = fopen("dados.txt", "r");
    FILE* output = fopen("ordenado.txt", "w");

    int chunkSize = 100; // Tamanho das subfitas (ajuste conforme necessário)

    externalSort(input, output, chunkSize);

    fclose(input);
    fclose(output);

    printf("Ordenação externa concluída com sucesso.\n");

    return 0;
}

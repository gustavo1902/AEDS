#include <stdio.h>

// Definição do registro Aluno
struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    // Declaração de um registro Aluno
    struct Aluno aluno1 = {"João", 20, 8.5};

    // Ponteiro para o registro Aluno
    struct Aluno *ponteiroAluno;

    // Atribuir o endereço do registro aluno1 ao ponteiro
    ponteiroAluno = &aluno1;

    // Exibir as informações do aluno através do ponteiro
    printf("Nome: %s\n", ponteiroAluno->nome);
    printf("Idade: %d\n", ponteiroAluno->idade);
    printf("Nota: %.1f\n", ponteiroAluno->nota);

    return 0;
}

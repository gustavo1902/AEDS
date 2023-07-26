#include <stdio.h>

// Definição do registro Aluno
struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    // Declaração e inicialização de um registro Aluno
    struct Aluno aluno1 = {"João", 20, 8.5};

    // Atribuição de valores aos campos do registro
    strcpy(aluno1.nome, "Maria");
    aluno1.idade = 22;
    aluno1.nota = 9.0;

    // Exibir as informações do aluno
    printf("Nome: %s\n", aluno1.nome);
    printf("Idade: %d\n", aluno1.idade);
    printf("Nota: %.1f\n", aluno1.nota);

    return 0;
}

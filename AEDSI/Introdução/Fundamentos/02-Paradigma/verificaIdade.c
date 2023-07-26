#include <stdio.h>

int main() {
    int idade;

    // Solicitar a idade do usuário
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    // Verificar se o usuário é maior ou menor de idade
    if (idade >= 18) {
        printf("Você é maior de idade.\n");
    } else {
        printf("Você é menor de idade.\n");
    }

    return 0;
}

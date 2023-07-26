#include <stdio.h>
#include <stdlib.h> // Incluir a biblioteca stdlib.h para a função atof

int main() {
    char numero[100];
    float soma = 0.0; // Inicializar como 0.0 para garantir que seja um float
    int contador = 0;

    printf("Calculadora de Média\n\n");

    while (1) {
        printf("Digite um número (ou '.' caso não queira adicionar mais um número): ");
        scanf("%s", numero);

        if (numero[0] == '.') {
            break;
        }

        float num = atof(numero);
        soma += num;
        contador++;
    }

    if (contador > 0) {
        float media = soma / contador;
        printf("\nA média dos números é: %.2f\n", media);
    } else {
        printf("\nNenhum número foi digitado.\n");
    }

    return 0;
}

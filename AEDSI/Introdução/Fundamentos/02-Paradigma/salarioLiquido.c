#include <stdio.h>

int main() {
    float salarioBruto, descontoImpostos, salarioLiquido;

    // Solicitar o valor do salário bruto e desconto de impostos
    printf("Digite o valor do salário bruto: ");
    scanf("%f", &salarioBruto);

    printf("Digite o valor do desconto de impostos: ");
    scanf("%f", &descontoImpostos);

    // Calcular o salário líquido
    salarioLiquido = salarioBruto - descontoImpostos;

    // Exibir o resultado na tela
    printf("O salário líquido é: %.2f\n", salarioLiquido);

    return 0;
}

/*
Neste exercício, é utilizado o paradigma de programação estruturada com estruturas sequenciais. 
O programa solicita os valores ao usuário, realiza o cálculo do salário líquido e exibe o resultado na tela. 
Não há estruturas condicionais ou iterativas neste exemplo, apenas uma sequência de ações para atingir o objetivo.
*/
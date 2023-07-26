#include <stdio.h>

int main(){
    int opcao;
    float num1, num2;

    printf("Calculadora Simples\n");

    do{
        printf("\nEscolha um operação:\n");
        printf("1. Soma\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("5. Sair\n");

        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 4){
            printf("Digite o primeiro número: ");
            scanf("%f", &num1);

            printf("Digite o segundo número: ");
            scanf("%f", &num2);

            // Realize a operação selecionada aqui e mostre o resultado
            if (opcao == 1){
                printf("\n%.f + %.f = %.f\n", num1, num2, num1+num2);
            } else if (opcao == 2){
                printf("\n%.f - %.f = %.f\n", num1, num2, num1-num2);
            } else if (opcao == 3){
                printf("\n%.f * %.f = %.f\n", num1, num2, num1*num2);
            } else if (opcao == 4){
                printf("\n%.f / %.f = %.f\n", num1, num2, num1/num2);
            } else if (opcao == 5){
                printf("\nObrigado por usar a Calculadora\n");
            } else {
            printf("\nOpção inválida\n");
        }
        }
    } while(opcao!=5);

    return 0;
}
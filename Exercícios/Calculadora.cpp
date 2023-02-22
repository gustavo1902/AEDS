#include <iostream>

using namespace std;
int main(){
    char op;
    double num1;
    double num2;
    double resultado;
    cout << "**********Calculadora**********\n";
    cout << "Qual operação? (+-*/):";
    cin >> op;
    cout << "1º variavel: ";
    cin >> num1;
    cout << "2º variavel: ";
    cin >> num2;

    switch(op){
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            resultado = num1 / num2;
            break;
    }
    cout << "*******************************";
    return 0;
}
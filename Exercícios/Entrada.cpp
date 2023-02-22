#include <iostream>

using namespace std;
int main(){

    string nome;
    int idade;
    cout << "Qual o seu nome?: ";
    cin >> nome;
    cout << "Qual a sua idade?: ";
    cin >> idade;
    cout << "Olá " << nome;
    cout << "Você tem " << idade << " anos";
    return 0;
}
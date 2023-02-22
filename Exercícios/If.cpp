//If declarações

#include <iostream>

using namespace std;

int main (){
    int idade;

    cout << "Qual a sua idade: ";
    cin >> idade;

    if(idade >= 18){
        cout << "Adulto!";
    }
    else{
        cout << "Menor de idade!";
    }
    return 0;
}
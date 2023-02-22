#include <iostream>

using namespace std;
/*
int main(){

    int temperatura;
    cout << "Informe a temperatura: ";
    cin >> temperatura;

    if (temperatura > 0  && temperatura < 30){
        cout << "A temperatura está boa!";
    } 
    else{
        cout << "A temperatura está ruim!";
    }
    return 0;
}
*/

int main(){

    int temperatura;
    bool ensolarado = true;

    cout << "Informe a temperatura: ";
    cin >> temperatura;

    if (temperatura <= 0 || temperatura >= 30){
        cout << "A temperatura está boa!";
    } 
    else{
        cout << "A temperatura está ruim!";
    }
    if(!ensolarado){
        cout << "Está ensolarado!";   
    }
    else{
        cout << "Não está ensolarado!";
    }
    return 0;
}


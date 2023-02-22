#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double a;
    double b;
    double c;
    double x;

    cout << "Qual o valor de A: ";
    cin >> a;
    cout << "Qual o valor de B: ";
    cin >> b;

    c = sqrt(pow(a,2)+pow(b,2)); 

    cout << "O valor da hipotenusa é: " << c;

    return 0;
}
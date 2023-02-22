#include <iostream>

int main(){
    const double PI = 3.14159;
    const int LIGHT_SPEED = 299792458;
    const int WIDTH = 1920;
    const int HEIGHT = 1080;

    double raio;
    std::cout << "Digite o raio do círculo: ";
    std::cin >> raio;

    double area = PI * raio * raio;

    std::cout << "A área do círculo é: " << area << std::endl;

    return 0;
}

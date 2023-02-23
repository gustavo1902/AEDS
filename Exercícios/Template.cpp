#include <iostream>

template <typename T, typename U>
T maior(T a, U b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << maior(3, 4.5) << std::endl; // retorna 4.5
    std::cout << maior(5.6, 2) << std::endl; // retorna 5.6
    std::cout << maior('a', 'b') << std::endl; // retorna 'b'
    
    return 0;
}

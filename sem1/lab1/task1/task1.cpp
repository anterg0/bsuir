#include <iostream>

int main() {
    double x,a,b,c;
    std::cout << "Введи значение x: ";
    std::cin >> x;
    c = x * x;
    a = 69 * c + 8;
    b = x * (23 * c + 32);
    std::cout << a + b << "\n" << a - b << "\n";
    return 0;
}

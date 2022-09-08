#include <iostream>
#include <climits>

int main() {
    int a = 0,b = 0;
    std::cout << "Введите число а: ";
    std::cin >> a;
    std::cin.clear();
    std::cout << "Введите число b: ";
    std::cin >> b;
    std::cin.clear();
    while (a >= INT_MAX || b >= INT_MAX) {
        std::cout << "Одна из переменных переполнилась, введите новые.\n";
        std::cin.clear();
        std::cout << "Введите число а: ";
        std::cin >> a;
        std::cin.clear();
        std::cout << "Введите число b: ";
        std::cin >> b;
        std::cin.clear();
    }
    a = a xor b;
    b = b xor a;
    a = a xor b;
    std::cout << a << " " << b;
    return 0;
}

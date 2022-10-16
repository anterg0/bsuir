#include <iostream>
#include <cmath>

int powint(int m, int pow) {
    if (pow == 0) {
        return 1;
    }
    for (int i = 1; i <= pow; i++) {
        m *= m;
    }
    return m;
}

int main() {
    int n, a;
    std::cout << "Введите кол-во членов прогрессии: ";
    std::cin >> n;
    std::cout << "\nВведите число первый член прогрессии: ";
    std::cin >> a;
    for (int i = 1; i <= n;i++) {
        a += (a * powint(2, (i - 1)) * powint(-1, (i - 1)));
    }
    std::cout << "\n" << a;
    return 0;
}
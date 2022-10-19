#include <iostream>
#include <cmath>

int main() {
    long double result = 0,d,an,a0,n = 0;
    std::cout << "Введите d,a0,an: ";
    std::cin >> d >> a0 >> an;
    n = ((an - a0) / d) + 1;
    if (!(d) || !((an - a0) / d)) {
        std::cout << "Такой прогрессии не существует";
    }
    result = (-3 * a0  * (pow(-2,n) * -1) - (d * (3 * pow(-2,n) * n + 
pow(-2, n + 1) + 2)) ) / 9;
    std::cout << result;
    return 0;
}


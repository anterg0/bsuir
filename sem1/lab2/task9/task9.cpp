#include <iostream>
#include <cmath>

int main() {
    double x,y,z,b,a;
    double f = 0;
    int N;
    
    std::cout << "Выберите значение f(x): \n1. 2x\n2. x^3\n3. x/3\n";
    std::cin >> N;
    std::cout << "Введите число z: ";
    std::cin >> z;
    
    if (z > 0) {
        x = 1 / ((z * z) + (2 * z));
    }
    else x = 1 - (z * z * z);
    
    switch (N) {
        case 1:
            f = 2 * x;
            break;
        case 2:
            f = x * x * x;
            break;
        case 3:
            f = x / 3;
            break;
    }
    std::cout << "Введите числа a, b: ";
    std::cin >> a >> b;
    y = ((2.5 * a * exp(-3 * x)) - (4 * b * x * x)) / (log(fabs(x)) + f);
    std::cout << "y = " << y;
    return 0;
}


#include <iostream>
#include <cmath>

int main() {
    long double a,b,c,x1,x2,x3,x4,t1,t2,D,p,q,Q,F;
    int N;
    std::cout << "Выберите уравнение: \n1. ax^4 + bx^2 + c = 0\n2. ax^4 + 
bx^3 + cx^2 + bx + a = 0\n3. x^3 + px + q = 0\n";
    std::cin >> N;
    switch(N) {
        case 1:
            std::cout << "Введите числа a, b, c : ";
            std::cin >> a >> b >> c;
            if (a == 0) {
                if (b == 0 && c == 0) {
                    std::cout << "x - любое число";
                    return 0;
                }
                else if (b == 0 && c != 0) {
                    std::cout << "Нет решений";
                    return 0;
                }
                else if (b != 0 && c == 0) {
                    std::cout << "x = 0 - единственное решение";
                    return 0;
                }
                else if (b != 0 && c != 0) {
                    if (!((-c / b) < 0)) {
                        x1 = sqrtl(-c / b);
                        x2 = -sqrtl(-c / b);
                        std::cout << "x1 = " << x1 << " x2 = " << x2;
                        return 0;
                    }
                    else {
                        std::cout << "Нет решений";
                        return 0;
                    }
                }
            }
            D = (b * b) - (4 * a * c);
            if (D > 0) {
                t1 = (-b + sqrt(D)) / (2 * a);
                t2 = (-b - sqrt(D)) / (2 * a);
                x1 = sqrt(t1);
                x2 = -sqrt(t1);
                x3 = sqrt(t2);
                x4 = -sqrt(t2);
                std::cout << "x1 = " << x1 << "\nx2 = " << x2 << "\nx3 = " 
<< x3 << "\nx4 = " << x4;
                return 0;
            }
            if (D == 0) {
                t1 = -b / (2 * a);
                x1 = sqrt(t1);
                x2 = -sqrt(t1);
                std::cout << "x1 = " << x1 << "\nx2 = " << x2;
                return 0;
            }
            if (D < 0) {
                std::cout << "Дискриминант меньше нуля.";
                return 0;
            }
            break;
        case 2:
            std::cout << "Введите числа a, b, c : ";
            std::cin >> a >> b >> c;
            if (a == 0) {
                if (b == 0 && c == 0) {
                    std::cout << "x - любое число";
                    return 0;
                }
                else if (b == 0) {
                    std::cout << "x = 0 - единственное решение";
                    return 0;
                }
                else if (c == 0) {
                    std::cout << "Нет решений";
                    return 0;
                }
                D = (c * c) - (4 * b * b);
                if (!(D < 0)) {
                    x2 = ((-c + sqrtl(D)) / (2 * b));
                    x3 = ((-c - sqrtl(D)) / (2 * b));
                    std::cout << "x1 = 0" << " x2 = " << x2 << " x3 = " << 
x3;
                    return 0;
                }
                else {
                    std::cout << "Дискриминант меньше нуля";
                    return 0;
                }
            }
            else if (a != 0) {
                D = b * b - 4 * a * (c - 2 * a);
                if (D < 0) {
                    std::cout << "Решений нет";
                    return 0;
                }
                t1 = (-b - sqrt(D)) / (2 * a);
                t2 = (-b + sqrt(D)) / (2 * a);
                D = t1 * t1 - 4;
                if (!(D < 0)) {
                    x1 = (t1 - sqrt(D)) / 2;
                    x2 = (t1 + sqrt(D)) / 2;
                    std::cout << "x1 = " << x1 << " x2 = " << x2;
                    return 0;
                }
                D = t2 * t2 - 4;
                if (!(D < 0)) {
                    x1 = (t2 - sqrt(D)) / 2;
                    x2 = (t2 + sqrt(D)) / 2;
                    std::cout << "x1 = " << x1 << " x2 = " << x2;
                    return 0;
                }
            }
            else {
                std::cout << "Решений нет";
                return 0;
            }
            break;
        case 3:
            std::cout << "Введите числа p, q: ";
            std::cin >> p >> q;
            long double al,bet;
            Q = ((p / 3) * (p / 3) * (p / 3)) + ((q / 2) * (q / 2));
            al = cbrtl((-1 * q / 2) + sqrtl(Q));
            bet = cbrtl((-1 * q / 2) - sqrtl(Q));
            F = acos(((-1 * q / 2) * sqrt((3 / (-1 * p))) * (3 / (-1 * p)) 
* (3 / (-1 * p))));
            if (Q < 0) {
                x1 = 2 * sqrtl(-1 * p / 3) * cos(F / 3);
                x2 = 2 * sqrtl(-1 * p / 3) * cos((F / 3) + (2 * acos(-1) / 
3));
                x3 = 2 * sqrtl(-1 * p / 3) * cos((F / 3) - (2 * acos(-1) / 
3));
                std::cout << "x1 = " << x1 << " x2 = " << x2 << " x3 = " 
<< x3;
                return 0;
            }
            else {
                x1 = al + bet;
                std::cout << "x1 = " << x1;
                return 0;
            }
            break;
    }
}


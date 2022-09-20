#include <iostream>
#include <cmath>

int main() {
    double x1,y1,x2,y2,r,R,a;
    std::cin >> x1 >> y1 >> x2 >> y2 >> r >> R;
    a = sqrt(( (y2 - y1) * (y2 - y1) ) + ( (x2 - x1) * (x2 - x1) ));
    if (x1 == x2 && y1 == y2) {
        if (r < R) {
            std::cout << "Да";
            return 0;
        }
        else if (r > R) {
            std::cout << "Да, но справедливо обратное для двух фигур";
            return 0;
        }
    }
    if (x1 != x2 || y1 != y2) {
        if (a != r + R) {
            std::cout << "Фигуры пересекаются";
            return 0;
        }
    }
    std::cout << "Ни одно условие не выполняется";
    return 0;
}


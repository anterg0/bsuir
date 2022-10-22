#include <iostream>
#include <cmath>

int fact(int k) {
    int res = 1;
    for (int q = 0; q <= k; q++) {
         res *= q;
    }
    return res;
}

int main() {
    long double s, y = 0, x;
    int n = 0,i = 1, x_count = 0;
    std::cout << "Введите число ряда: ";
    std::cin >> n;
    std::cout << "Введите кол-во вводимых x: ";
    std::cin >> x_count;
    while (x_count >= i) {
        s = 0;
        std::cout << "Введите x: ";
        std::cin >> x;
        i++;
        for (int i1 = 1; n >= i1 ; i1++) {
            s += powl(-1, i1) * ((powl(2 * x, 2 * i1)) /  fact(2 * i1));
        }
        y = 2 * ( (cosl(x) * cosl(x)) - 1);
        std::cout << "s(x) = " << s << "\ny(x) = " << y << "\n";
    }
    return 0;
}


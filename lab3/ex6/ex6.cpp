#include <iostream>
#include <cmath>

int main() {
    long double step, x_minf = 0, minf = 1e20, f, x = 0;
    int n;
    std::cout << "Введитие кол-во раз поиска корня уравнения: ";
    std::cin >> n;
    step = 1. / n;
    for (int i = 1; i <= n; i++) {
        f = sinhl(x) + acosl(x) - 1.5;
        if (fabs(f) < minf) {
            minf = fabs(f);
            x_minf = x;
        }
        x += step;
    }
    std::cout << x_minf << "\n";
    return 0;
}


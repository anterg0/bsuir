#include <iostream>
#include <cmath>

int main() {
    double d = 1,eps = 0.001;
    int n = 0;
    do {
        d = powl(1. / 2., n) + powl(1. / 3., n);
        n++;
    }
    while (d > eps);
    std::cout << d;
    return 0;
}


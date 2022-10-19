#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846
#define E 2.71828182845904523536

long double sinx (long double x) {
    x = x - (long long) (x / (2 * PI)) * 2 * PI;
    if (x < 0) x = x + 2 * PI;
    long double y = x, z = x;
    for (int n = 1; n < 1000000; n++) {
        y = y / (2 * n + 1) / (2 * n) * x * x;
        if ((y < 1e-52) && (y > -1e-52)) break;
        z = z + (n & 1 ? -1 : 1) * y;
    }
    return z;
}

long double cosx (long double x) {
    x = x - (long long) (x / (2 * PI)) * 2 * PI;
    if (x < 0) x = x + 2 * PI;
    long double y = 1, z = 1;
    for (int n = 1; n < 1000000; n++) {
        y = y / (2 * n) / (2 * n - 1) * x * x;
        if ((y < 1e-52) && (y > -1e-52)) break;
        z = z + (n & 1 ? -1 : 1) * y;
    }
    return z;
}

long double lnabsx (long double x) {
    if (x < 0) x = x * (-1);
    long double l = 0;
    while (x > E) {
        x = x / E;
        l = l + 1;
    }
    while (x < 1) {
        x = x * E;
        l = l - 1;
    }
    if (x > 1) {
        x = x / (x - 1);
        long double y = 1 / x, z = 1 / x;
        for (int n = 2; n < 1000000; n++) {
            y = y / n / x * (n - 1);
            if ((y < 1e-52) && (y > -1e-52)) break;
            z = z + y;
        }
        return z + l;
    }
    long double y = (x - 1), z = (x - 1);
    for (int n = 2; n < 1000000; n++) {
        y = y / n * (n - 1) * (x - 1);
        if ((y < 1e-52) && (y > -1e-52)) break;
        z = z + y;
    }
    return z + l;
}

int main () {
    long double x;
    std::cin >> x;
    std::cout << "sin(x) = " << sinx(x) << "\n";
    std::cout << "cos(x) = " << cosx(x) << "\n";
    std::cout << "ln(|x|) = " << lnabsx(x) << "\n";
    return 0;
}


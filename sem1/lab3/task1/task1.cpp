#include <iostream>

int main() {
    std::cout.precision(20);
    double N = 0,a,b;
    int i = 1,mod;
    while (i <= 30) {
        mod = i % 2;
        if (mod == 0) {
            a = i / 2.;
            b = i * i * i;
        }
        else {
            a = i;
            b = i * i;
        }
        N += ((a - b) * (a - b));
        i++;
    }
    std::cout << N;
    return 0;
}


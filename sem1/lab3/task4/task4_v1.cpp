#include <iostream>

int main() {
    double n,sum = 0,mod;
    int i = 1;
    std::cin >> n;
    while (i <= n) {
        mod = i % 2;
        if (mod == 0) {
            sum += i;
        }
        i++;
    }
    std::cout << sum;
    return 0;
}


#include <iostream>

int main() {
    int n,sum = 0,mod;
    int i = 2;
    std::cin >> n;
    mod = n % 2;
    if (mod != 0) {
        n--;
        sum = ((i + n) * n ) / 4;
    }
    else {
        sum = ((i + n) * n ) / 4;
    }
    std::cout << sum;
    return 0;
}


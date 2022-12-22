#include <iostream>

int main() {
    long long number;
    int t;
    std::cin >> t;
    for (int i = 0; i < t;i++) {
        std::cin >> number;
        std::cout << ((number + 1) / 10) << '\n';
    }
    return 0;
}

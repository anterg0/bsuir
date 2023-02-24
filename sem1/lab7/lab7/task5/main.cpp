#include <iostream>

long long bebrochka(long long number) {
    long long result;
    result = ((number + 1) / 10);
    return result;
}

int main() {
    long long number;
    int t;
    std::cin >> t;
    for (int i = 0; i < t;i++) {
        std::cin >> number;
        std::cout << bebrochka(number);
    }
    return 0;
}

#include <iostream>

int main() {
    unsigned long int K;
    std::cin >> K;
    if (K % 100 >= 10 && K % 100 <= 20) {
        std::cout << "Мы нашли " << K << " грибов в лесу";
        return 0;
    }
    std::cout << "Мы нашли " << K << " гриб" << (K > 10 && K < 21 ? "ов" : K == 1 || K % 10 == 1 ? "" :
                K > 1 && K < 5 || K % 10 > 1 && K % 10 < 5 ? "а" : "ов") << " в лесу";
    return 0;
}

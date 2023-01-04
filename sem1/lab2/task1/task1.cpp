#include <iostream>
#include <cmath>

int main() {
    double n1,n2,m,m1;
    std::cin >> n1 >> n2;
    if (n1 == 0 && n2 == 0) {
        std::cout << "ERROR";
        return 0;
    }
    m = fmod(n1, n2);
    m1 = fmod(n2, n1);
    if (m == 0) {
        std::cout << "YES";
    }
    else {
        if (m1 == 0) {
            std::cout << "YES";
        }
        else {
            std::cout << "NO";
        }
    }
    return 0;
}

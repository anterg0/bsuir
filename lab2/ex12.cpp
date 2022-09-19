#include <iostream>

int main() {
    long double a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;
    if (a == 0 || b == 0 || c == 0 || x == 0 || y == 0 || a < 0 || b < 0 || c < 0 || x < 0 || y < 0) {
        std::cout << "Incorrect input";
    }
    else if (a <= x && c <= y) {
        std::cout << "YES";
    }
    else if (b <= x && c <= y) {
        std::cout << "YES";
    }
    else if (b <= x && a <= y) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
    return 0;
}

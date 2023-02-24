#include <iostream>

int main() {
    double x,y,z;
    std::cin >> x >> y >> z;
    if (z < x + y && x < z + y && y < z + x) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
    return 0;
}

#include <iostream>
#include <iomanip>

int main() {
    std::cout.precision(20);
    long double Z,a,b,c,d;
    std::cin >> a >> b >> c >> d;
    if (c == 0 || c == -0) {
        std::cout << "ERROR";
        return 0;
    }
    else if (c >= d && a < d) {
        Z = a + (b / c);
    }
    else if (c < d && a >= d) {
            Z = a - (b / c);
        }
        else {
            Z = 0;
        }
    std::cout << Z;
    return 0;
    }

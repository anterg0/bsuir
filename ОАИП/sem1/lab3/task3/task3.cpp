#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    long double x = 0,A = 0,B = M_PI / 2,H,M = 20,y;
    for (int i = 0; x < M_PI / 2; i++) {
        H = (B - A) / M;
        x = A + (i * H);
        y = sinl(x) - cosl(x);
        std::cout << std::fixed << "y = " << y << "\n";
    }
    return 0;
}


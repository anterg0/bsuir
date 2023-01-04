#include <iostream>
#include <cmath>

int main() {
    double R,P,Q,r;
    std::cin >> R >> P >> Q;
    Q = Q * (M_PI / 180.);
    r = P * sin(Q) / 2;
    if (R > r) {
        std::cout << "Шар не проходит в ромбообразное отверстие";
    }
    else if (R <= r) {
        std::cout << "Шар проходит в ромбообразное отверстие";
    }
    return 0;
}


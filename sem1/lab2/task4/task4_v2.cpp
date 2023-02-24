#include <iostream>

int main() {
    double x,y;
    std::cin >> x >> y;
    bool check = x < y;
    std::cout << (check ? y : x);
    return 0;
}


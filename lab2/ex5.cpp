#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    long double k,x,y,a1,a2,a3,a4,a;
    std::cout.precision(22);
    std::cin >> k >> x >> y;
    if (k < 0) {
        k = k * -1;
        x = x * -1;
        y = y * -1;
    }
    if (x >= k && y >= k) {
        a = sqrtl(((k - x) * (k - x)) + ( (k - y) * (k - y) ));
        std::cout << a;
        return 0;
    }
    if (x >= k && y <= 0) {
        a = sqrtl(((k - x) * (k - x)) + ( (0 - y) * (0 - y) ));
        std::cout << a;
        return 0;
    }
    if (x <= 0 && y <= 0) {
        a = sqrtl(((0 - x) * (0 - x)) + ( (0 - y) * (0 - y) ));
        std::cout << a;
        return 0;
    }
    if (x <= 0 && y >= k) {
        a = sqrtl(((0 - x) * (0 - x)) + ( (k - y) * (k - y) ));
        std::cout << a;
        return 0;
    }
    if (y <= 0 && x > 0 && x <= k) {
        a = fabsl(0 - y);
        std::cout << a;
        return 0;
    }
    if (y > 0 && x <= 0 && y <= k) {
        a = fabsl(0 - x);
        std::cout << a;
        return 0;
    }
    if (y >= k && x > 0 && x <= k) {
        a = fabsl(y - k);
        std::cout << a;
        return 0;
    }
    if (y <= k && y > 0 && x >= k) {
        a = fabsl(x - k);
        std::cout << a;
        return 0;
    }
    
    
    
    
    a1 = fabsl(x);
    a2 = fabsl(k - x);
    a3 = fabsl(k - y);
    a4 = fabsl(y);
    if (x <= k && y <= k && x >= 0 && y >= 0) {
        if (a1 <= a2 && a1 <= a3 && a1 <= a4) {
            std::cout << a1;
        }
        else if (a2 <= a1 && a2 <= a3 && a2 <= a4) {
            std::cout << a2;
        }
        else if (a3 <= a2 && a3 <= a1 && a3 <= a4) {
            std::cout << a3;
        }
        else if (a4 <= a2 && a4 <= a3 && a4 <= a1) {
            std::cout << a4;
        }
    }
    return 0;
    }


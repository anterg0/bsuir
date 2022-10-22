#include <iostream>

int main() {
    long double W,H,x1,y1,x2,y2,w,h,a,b;
    std::cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    if (x1 < w && y1 < h) {
        a = h - y1;
        b = w - x1;
        if (y2 + a <= H) {
                std::cout << a;
                return 0;
            }
        if (x2 + b <= W) {
                    std::cout << b;
                    return 0;
                }
        if (y2 + a <= H && x2 + b <= W && a == b) {
            std::cout << a;
            return 0;
        }
        if (y2 + a > H && x2 + b > W) {
            std::cout << "-1";
            return 0;
        }
    }
    if (x1 >= W || y1 >= H || x2 <= 0 || y2 <= 0) {
        std::cout << "-1";
        return 0;
    }
    else std::cout << "0";
    return 0;
}


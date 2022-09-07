#include <iostream>
#include <cmath>

int main() {
    int h1,min1,h2,min2,s1,s2,s3,h3,min3;
    std::cin >> h1 >> min1 >> h2 >> min2;
    s1 = (h1 * 3600) + (min1 * 60);
    s2 = (h2 * 3600) + (min2 * 60);
    if (s2 < s1) {
        s3 = (86400 - (s1 - s2));
    }
    else {
        s3 = s2 - s1;
    }
    h3 = s3 / 3600;
    min3 = fmod(s3, 3600);
    min3 = min3 / 60;
    std::cout << (h3 < 10 ? "0" : "") << h3 << ":" << (min3 < 10 ? "0" : "") << min3;
    return 0;
}

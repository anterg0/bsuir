#include <iostream>
#include <cmath>

int main() {
    int n,count,i1,num = 0,res;
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        count = 1;
        res = 0;
        i1 = i;
        while((i1 /= 10) > 0) count++;
        for(int q = 1; q <= count; q++) {
            num = i / int(pow(10, (q - 1) )) % 10;
            res += pow(num, count);
        }
        if (res == i) std::cout << res << "\n";
    }
    return 0;
}


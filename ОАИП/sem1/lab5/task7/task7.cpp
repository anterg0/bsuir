#include <iostream>
#include <cmath>

long long binpow(unsigned long long k, unsigned long long n, long long m) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return (binpow(k, n - 1, m) * k) % m;
    else {
        long long bebra = binpow(k, n / 2, m);
        return (bebra * bebra) % m;
    }
}

int main() {
    int i = 0;
    long long k,n,t;
    std::cin >> k >> n >> t;
    while (k + n + t) {
        int m = 1;
        m = pow(10, t);
        i++;
        std::cout << "Case #" << i << ": " << (binpow(k, n, m) % m) << '\n';
        std::cin >> k >> n >> t;
    }
    return 0;
}



#include <iostream>
int m;

long long binpow(long long a, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 1) return (binpow(a, n - 1) * a) % m;
    else {
        long long bruh = binpow(a, n / 2);
        return (bruh * bruh) % m;
    }
}

long long answer(long long L, std::string s1, std::string s2) {
    long long bruhSize = s1.size() + s2.size();
    long long sum = 0;
    if (bruhSize <= L) {
        if (s1 == s2) return binpow(26, L - bruhSize);
        else return binpow(26, L - bruhSize) * 2;
    }
    else {
        long long finder = s1.find(s2[0]);
        long long finder2 = s2.find(s1[0]);
        if (finder < 0 && finder2 < 0) return 0;
        else if (finder >= 0) {
            std::string sBruh = s1.substr(finder,s1.size()), s2Bruh = s2.substr(0,(sBruh.size() ? sBruh.size() : 1));
            if (sBruh == s2Bruh) sum++;
        }
        if (finder2 >= 0) {
            std::string sBruh = s2.substr((s1[0] == s1[s1.size() - 1] ? finder2 + 1 : finder2),s2.size()), s2Bruh = s1.substr(0,(sBruh.size() ? sBruh.size() : 1));
            if (sBruh == s2Bruh) sum++;
        }
        return sum;
    }
    return 0;
}

int main() {
    std::string s1(200,0),s2(200,0);
    long long L;
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        std::cin >> L >> m;
        std::cin >> s1 >> s2;
        std::cout << (answer(L, s1, s2)) % m << '\n';
    }
    return 0;
}


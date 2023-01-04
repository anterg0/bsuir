#include <iostream>

int a[19], b[19], c[19][78], r[78];

int main() {
    long long n;
    std::cin >> n;
    long long m = n - 1;
    if (n % 2) m = m / 2;
    else n = n / 2;
    for (int i = 19 - 1; i > -1; i--) {
        a[i] = n % 10;
        n = n / 10;
    }
    for (int i = 19 - 1; i > -1; i--) {
        b[i] = m % 10;
        m = m / 10;
    }
    for (int i = 19 - 1; i > -1; i--) {
        int o = 0, p = 78 - 1 - (19 - i - 1);
        for (int j = 19 - 1; j > -1; j--) {
            c[i][p] = (a[j] * b[i] + o) % 10;
            o = (a[j] * b[i] + o) / 10;
            p = p - 1;
        }
        while (o) {
            c[i][p] = o % 10;
            o = o / 10;
            p = p - 1;
        }
        o = 0;
        int j = 78 - 1;
        for (; j > -1; j--) {
            int p = (r[j] + c[i][j] + o);
            r[j] = p % 10;
            o = p / 10;
        }
        while (o) {
            r[j] = (o % 10);
            o = o / 10;
            j = j - 1;
        }
    }
    int o = 1;
    for (int j = 78 - 1; j > -1; j--) {
        int p = r[j] + o;
        r[j] = p % 10;
        o = p / 10;
    }
    bool f = 0;
    for (int i = 0; i < 78; i++) {
        if ((f == 0) && (r[i] != 0)) f = 1;
        if (f == 1) std::cout << r[i];
    }
    std::cout << "\n";
    return 0;
}

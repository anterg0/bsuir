#include <iostream>

int main() {
    int n,m;
    std::cin >> n;
    int a[n][n];
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            std::cin >> a[j][i];
        }
    }
    std::cin >> m;
    int b[m][m];
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < m; i++) {
            std::cin >> b[j][i];
        }
    }
    int c[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j != (n - 1)) {
                std::cout << c[i][j] << " ";
            }
            else {
                std::cout << c[i][j];
            }
        }
        std::cout << "\n";
    }
    return 0;
}


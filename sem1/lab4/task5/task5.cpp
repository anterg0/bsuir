#include <iostream>

int main() {
    int n,m;
    std::cin >> n >> m;
    int A[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> A[i][j];
        }
    }
    int B[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != 0) {
                if (A[i][j - 1] > A[i][j]) {
                    A[i][j] = A[i][j - 1];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != 0) {
                A[i][j] = A[i][j];
                if (A[i - 1][j] > A[i][j]) {
                    A[i][j] = A[i - 1][j];
                }
                else A[i][j] = A[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

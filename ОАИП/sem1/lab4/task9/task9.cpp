#include <iostream>

int main() {
    int n,d1 = 0,d2 = 0,d3 = 0,d4 = 0,max;
    std::cin >> n;
    unsigned int ***a = nullptr;
    a = (unsigned int***)malloc(n * n * n * sizeof(unsigned int**));
    for (int i = 0; i < n; i++) {
        a[i] = (unsigned int**) malloc(n * n * n * sizeof(unsigned int*));
    }
    for (int j = 0; j < n; j++) for (int i = 0; i < n; i++) {
        a[j][i] = (unsigned int*) malloc(n * n * n * sizeof(unsigned int));
    }
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                std::cin >> a[i][j][k];
                
            }
        }
    }
    //
    for (int i = 0; i < n; i++) {
        d1 += a[i][i][i];
    }
    for (int i = 0; i < n; i++) {
        int j = n - 1;
        d2 += a[j][j][i];
        j--;
    }
    for (int i = 0; i < n; i++) {
        int j = n - 1;
        d3 += a[j][i][i];
        j--;
    }
    for (int i = 0; i < n; i++) {
        int j = n - 1;
        d4 += a[i][j][i];
        j--;
    }
    max = d1;
    if (d2 > max) max = d2;
    if (d3 > max) max = d3;
    if (d4 > max) max = d4;
    std::cout << max;
    
    //
    for (int j = 0; j < n; j++) for (int i = 0; i < n; i++) {
        free(a[j][i]);
    }
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}



#include <iostream>
 
int main()
{
    int k,g,count = 0;
    std::cin >> k >> g;
    int arr[k][g];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < g; j++) {
            std::cin >> arr[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < g; j++) {
            if (i == 0 && j == 0) {
                if (arr[i][j] < arr[i][j + 1] && arr[i][j] < arr[i + 1][j + 1] && arr[i][j] < arr[i + 1][j]) count++;
            }
            if (i == 0 && j != 0 && j != (g - 1)) {
                if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i][j + 1] && arr[i][j] < arr[i + 1][j - 1] && arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i + 1][j + 1]) count++;
            }
            if (i == 0 && j == (g - 1)) {
                if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i + 1][j - 1] && arr[i][j] < arr[i + 1][j]) count++;
            }
            if (i != (k - 1) && i != 0 && j == (g - 1)) {
                if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i + 1][j - 1] && arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i - 1][j - 1]) count++;
            }
            if (i == (k - 1) && j == (g - 1)) {
                if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i - 1][j - 1] && arr[i][j] < arr[i][j - 1]) count++;
            }
            if (i == (k - 1) && j != (g - 1) && j != 0) {
                if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i - 1][j - 1] && arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i - 1][j + 1] && arr[i][j] < arr[i][j + 1]) count++;
            }
            if (i == (k - 1) && j == 0) {
                if (arr[i][j] < arr[i][j + 1] && arr[i][j] < arr[i - 1][j + 1] && arr[i][j] < arr[i - 1][j]) count++;
            }
            if (i != 0 && i != (k - 1) && j == 0) {
                if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i - 1][j + 1] && arr[i][j] < arr[i][j + 1] && arr[i][j] < arr[i + 1][j + 1] && arr[i][j] < arr[i + 1][j]) count++;
            }
            else if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i - 1][j - 1] && arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i + 1][j - 1] && arr[i][j] < arr[i + 1][j] && arr[i][j] < arr[i + 1][j + 1] && arr[i][j] < arr[i][j + 1] && arr[i][j] < arr[i + 1][j + 1]) count++;
        }
    }
    std::cout << count;
    return 0;
}

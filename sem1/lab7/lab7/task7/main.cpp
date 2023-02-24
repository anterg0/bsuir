#include <iostream>

bool is_bidecimal(int* arr);

int main() {
    int arr[11000][170], bruh;
    std::cin >> bruh;
    arr[0][169] = 1;
    arr[0][0] = 169;
    int index = 1, start = 0, end = 0;
    while (index <= bruh) {
        for (int i = start; i <= end; i++) {
            for (int j = 0; j < 170; ++j) arr[index][j] = arr[i][j];
            int k = arr[index][0];
            arr[index][k - 1] = 1;
            arr[index][k] = 0;
            arr[index][0]--;
            if (is_bidecimal(arr[i])) ++index;
        }
        for (int i = start; i <= end; i++) {
            for (int j = 0; j < 170; ++j) arr[index][j] = arr[i][j];
            int k = arr[index][0];
            arr[index][k - 1] = 1;
            arr[index][0]--;
            if (is_bidecimal(arr[i])) ++index;
        }
        start = end + 1;
        end = index - 1;
    }
    for (int i = arr[bruh - 1][0]; i < 170; i++) std::cout << arr[bruh - 1][i];
    return 0;
}

bool is_bidecimal(int* arr) {
    int size = 170 - arr[0];
    int result[171];
    for (int i = 1; i < 170; i++) result[i] = arr[i];
    for (;size > 0; size--) {
        for (int i = arr[0]; i < 170; i++) {
            result[i + 1] += (result[i] % 2) * 10;
            result[i] /= 2;
        }
    }
    if (result[169] % 2 == 0) return true;
    else return false;
}

#include <iostream>

int main() {
    int arr[10000],xmin = 1e20, xmax = 0, i_max = 0, i_min = 0,zerocount = 0,arr_size;
    for (int i = 0; ; i++) {
        std::cin >> arr[i];
        if (std::cin.peek() == EOF) {
            arr_size = i + 1;
            break;
        }
    }
    for (int i = 1; i < arr_size; i++) {
        if (arr[i] > arr[i + 1] && arr[i] > xmax) {
            xmax = arr[i];
            i_max = i;
        }
        if (arr[i] < arr[i + 1] && arr[i] < xmin) {
            xmin = arr[i];
            i_min = i;
        }
    }
    if (i_max < i_min) {
        for (int i = i_max + 1; i < i_min; i++) {
            arr[i] = 0;
        }
    }
    else if (i_max > i_min) {
        for (int i = i_min + 1; i < i_max; i++) {
            arr[i] = 0;
        }
    }
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] == 0) zerocount++;
    }
    if (zerocount > (arr_size / 2)) {
        for (int i = 0; i < arr_size; i++) {
            if (arr[i] != 0) std::cout << arr[i] << " ";
        }
    }
    else {
        for (int i = 0; i < arr_size; i++) {
            std::cout << arr[i] << " ";
        }
    }
    return 0;
}

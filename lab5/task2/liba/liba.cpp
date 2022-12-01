#include <iostream>
#include "liba.hpp"

int* CreateArray(int n) {
    int *array = new int[n];
    return array;
}

bool intValidation(char b, int a) {
    if (b != '\n' && b != ' ') return true;
    if (a > 2147483647 || a < -2147483648) return true;
    return false;
}

void FillArray(int* array, int n) {
    std::cout << "Заполни массив: ";
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
        char b = getchar();
        if (intValidation(b,array[i])) {
            std::cout << "Неверный ввод.\nВведи элементы заново: ";
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            i = -1;
            continue;
        }
    }
}

int Sum(int* arr, int a, int b) {
    if (b < a)
        return 0;
    return arr[a - 1] * arr[a - 1] + Sum(arr, a + 1, b);
}

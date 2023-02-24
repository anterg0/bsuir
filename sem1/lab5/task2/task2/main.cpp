#include <iostream>

int* CreateArray(int n);

bool intValidation(char b, int a);

void FillArray(int* array, int n);

int Sum(int* arr, int a, int b);

int main() {
    while (true) {
        int n = 0;
        std::cout << "Введите размер массива: ";
        std::cin >> n;
        char b = getchar();
        if (intValidation(b,n)) {
            std::cout << "Неверный ввод.\n";
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            continue;
        }
        int *arr = CreateArray(n);
        FillArray(arr, n);
        std::cout << (Sum(arr, 1, n / 3) + Sum(arr, n / 3 + 1, n));
        std::cout << "\nВведите 'f' для повтора программы, либо любой другой символ для завершения программы.";
        char bebra;
        std::cin >> bebra;
        switch (bebra) {
            case 'f':
                continue;
                break;
            default:
                return 0;
                break;
        }
    }
}

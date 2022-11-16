#include <iostream>

bool DoubleValidation(char b, double a) {
    if (b != '\n' && b != ' ') return true;
    if (a > std::numeric_limits<double>::max() || a < std::numeric_limits<double>::min()) return true;
    return false;
}

bool intValidation(char b, int a) {
    if (b != '\n' && b != ' ') return true;
    if (a > 2147483647 || a < -2147483648) return true;
    return false;
}

void ArrOutput(double **arr, int n, int k) {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) std::cout << arr[i][j] << "\t";
        std::cout << '\n';
    }
}

double** CreateArr(int n, int k) {
    double** arr = new double*[n];
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) arr[i] = new double[k];
    for (int i = 0; i < n; i++) for (int j = 0; j < k; j++) {
        std::cin >> arr[i][j];
        char b = getchar();
        if (DoubleValidation(b, arr[i][j])) {
            std::cout << "Неверный ввод.\nВведи элементы массива заново: ";
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            j = -1;
            i = 0;
            continue;
        }
    }
    return arr;
}

int ZeroCount(double **arr, int n, int k) {
    int result = 0;
    std::cout << "Индексы нулевых элементов массива: ";
    for (int i = 0; i < n; i++) for (int j = 0; j < k; j++) {
        if (arr[i][j] == 0) {
            result++;
            std::cout << "(" << i << "," << j << ") ";
        }
    }
    // std::cout << "\nКол-во таких элементов: " << result << "\n";
    return result;
}

void ReverseArrOutput(double **arr, int n, int k) {
    for(int i = n - 1; i >= 0; i--) {
        for (int j = k - 1; j >= 0; j--) std::cout << arr[i][j] << "\t";
        std::cout << '\n';
    }
}

int main() {
    int n,k;
    while (true) {
        std::cout << "Введите размер массива: ";
        std::cin >> n;
        char b = getchar();
        if (intValidation(b, n)) {
            std::cout << "Неверный ввод. Введите всё заново.\n";
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            continue;
        }
        std::cin >> k;
        b = getchar();
        if (intValidation(b, n)) {
            std::cout << "Неверный ввод. Введите всё заново.\n";
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            continue;
        }
        double **array = CreateArr(n,k);
        ArrOutput(array,n,k);
        std::cout << "\n";
        int zeros = ZeroCount(array,n,k);
        std::cout << "\nКол-во таких элементов: " << zeros << "\n";
        ReverseArrOutput(array,n,k);
        return 0;
    }
}

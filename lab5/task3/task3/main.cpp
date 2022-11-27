#include <iostream>

bool intValidation(char b, int a) {
    if (b != '\n' && b != ' ') return true;
    if (a > 2147483647 || a < -2147483648) return true;
    return false;
}


void ArrOutput(int **arr, int n, int k) {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) std::cout << arr[i][j] << "\t";
        std::cout << '\n';
    }
}

int** CreateArr(int n, int k) {
    int** arr = new int*[n];
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) arr[i] = new int[k];
    for(int i = 0; i < n; i++) for (int j = 0; j < k; j++) {
        std::cin >> arr[i][j];
        char b = getchar();
        if (intValidation(b, arr[i][j])) {
            std::cout << "Неверный ввод.\nВведи элементы массива заново: ";
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            i = -1;
            continue;
        }
    }
    for(int i = 0; i < n; i++) for (int j = 0; j < k; j++) {
        if (arr[i][j] % 2 == 0) std::swap(arr[i][j], arr[i][i]);
    }
    return arr;
}

int Multiplication(int **arr, int n,int k) {
    int mul = 1;
    for(int i = 0; i < n; i++) for (int j = 0; j < k; j++) {
        mul *= arr[i][j];
    }
    return mul;
}

int main() {
    std::cout << "Дан двумерный динамический массив целых чисел А размерностью 𝑛 × 𝑘. Размерность массива ввести с клавиатуры. Значения элементов массива ввести с клавиатуры. Создать динамический массив из элементов, расположенных на главной диагонали матрицы и имеющих четное значение. Вычислить произведение элементов динамического массива.\nВыполнил Шпаковский Антон\n";
    while (true) {
        int n,k;
        std::cout << "Введите размер массива: ";
        std::cin >> n;
        char b = getchar();
        if (intValidation(b,n)) {
            std::cout << "Неверный ввод.\n";
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            continue;
        }
        std::cin >> k;
        b = getchar();
        if (intValidation(b,k)) {
            std::cout << "Неверный ввод.\n";
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            continue;
        }
        int **array = CreateArr(n,k);
        ArrOutput(array,n,k);
        std::cout << "\n";
        int multipl = Multiplication(array, n, k);
        std::cout << "Произведение всех элементов массива: " << multipl;
        std::cout << "Введите 'f' для повтора программы, либо любой другой символ для завершения программы.";
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

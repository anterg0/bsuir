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
    for (int i = 0; i < n; i++) {
        int odd = 1;
        for (int j = 0; j < k; j++) {
            if (odd < k) if (int(arr[i][j]) % 2 != 0) {
                std::swap(arr[i][j],arr[i][odd]);
                odd += 2;
            }
        }
    }
    int temp_i = 0;
    int temp_j = 0;
    int eventemp_i = 0;
    int eventemp_j = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (int(arr[i][j]) % 2 != 0 && j % 2 == 0) {
                temp_i = i;
                temp_j = j;
                std::swap(arr[eventemp_i][eventemp_j], arr[temp_i][temp_j]);
            }
            if (int(arr[i][j]) % 2 == 0 && j % 2 != 0) {
                eventemp_i = i;
                eventemp_j = j;
            }
             
        }
    }
    return arr;
}
 
double AverageArth(double **arr, int n, int k) {
    double sum = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < k; j++) {
        sum += arr[i][j];
    }
    return (sum / (n * k));
}
 
int main() {
    int n,k;
    std::cout << "Дан двумерный динамический массив целых чисел. Значения элементов данного массива ввести с клавиатуры. Создать динамический массив из элементов, расположенных в четных столбцах данного массива и имеющих нечетное значение. Вычислить среднее арифметическое элементов динамического массива.\nВыполнил Шпаковский Антон\n";
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
        double result = AverageArth(array,n,k);
        std::cout << "Среднее арифметическое всех элементов массива: " << result;
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

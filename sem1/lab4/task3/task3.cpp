#include <iostream>

int main()
{
    std::cout << "Задание: Дана вещественная квадратная матрица порядка N. Получить целочисленную квадратную матрицу, в которой элемент равен 1, если соответствующий ему элемент исходной матрицы больше элемента, расположенного на главной диагонали, и равен 0 в противном случае.\nВыполнил Шпаковский А.В.\nВариант 12.\n";
    while (true) {
        int n;
        std::cout << "Введите порядок матрицы n: ";
        std::cin >> n;
        if (n < 2 || (std::cin.peek() != '\n')) {
            std::cout << "Неверный ввод";
            std::cin.clear();
            std::cin.ignore(1000000000, '\n');
            std::cout << "\nЖелаете повторить? (y/n)";
            char a;
            std::cin >> a;
            switch(a) {
                case 'y':
                    continue;
                    break;
                case 'n':
                    return 0;
                    break;
                default:
                    return 0;
                    break;
            }
        }
        long double **arr = new long double* [n];
        for (int i = 0; i < n; i++) {
            arr[i] = new long double[n];
        }
        int **a = new int* [n];
        for (int i = 0; i < n; i++) {
            a[i] = new int[n];
        }
        std::cout << "Введите элементы матрицы: ";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> arr[i][j];
                if (std::cin.fail() || (std::cin.peek() != '\n')) {
                    std::cout << "Неверный ввод";
                    std::cin.clear();
                    std::cin.ignore(1000000000, '\n');
                    std::cout << "\nЖелаете заново ввести элементы матрицы? (y/n)";
                    char reset;
                    std::cin >> reset;
                    switch(reset) {
                        case 'y':
                            std::cout << "Введите элементы матрицы: ";
                            i = 0;
                            j = -1;
                            continue;
                            break;
                        case 'n':
                            return 0;
                            break;
                            
                        default:
                            return 0;
                            break;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] > arr[i][i]){
                    a[i][j] = 1;
                }
                else {
                    a[i][j] = 0;
                }
            }
        }
        std::cout << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << a[i][j] << "\t";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << arr[i][j] << "\t";
            }
            std::cout << "\n";
        }
        for (int i = 0; i < n; i++) {
            delete[] a[i];
        }
        delete[] a;
        for (int i = 0; i < n; i++) {
            delete[] arr[i];
        }
        delete[] arr;
        std::cout << "\nЖелаете повторить? (y/n)";
        char reset;
        std::cin >> reset;
        switch(reset) {
            case 'y':
                continue;
                break;
            case 'n':
                return 0;
                break;
            default:
                return 0;
                break;
        }
    }
}

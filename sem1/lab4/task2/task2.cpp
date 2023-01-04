#include <iostream>

int main() {
    std::cout << "Цель задания: Найти минимальный элемент в каждом столбце массива.\nВыполнил Шпаковский А.В.\nВариант 12.\n";
    int n,m,column = 0;
    while(true) {
        std::cout << "Введите число строк (n) и число столбцов (m): ";
        std::cin >> n >> m;
        if (n <= 0 || m <= 0 || (std::cin.peek() != '\n')) {
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
        int array[n][m];
        std::cout << "Введите элементы(" << n * m << ") массива: ";
        for (int i = 0; i < n; i++) {
            for (int i1 = 0; i1 < m; i1++) {
                std::cin >> array[i][i1];
                if (std::cin.fail() || (std::cin.peek() == 'e')) {
                    std::cout << "Неверный ввод";
                    std::cin.clear();
                    std::cin.ignore(1000000000, '\n');
                    std::cout << "\nЖелаете заново ввести элементы массива? (y/n)";
                    char a;
                    std::cin >> a;
                    switch(a) {
                        case 'y':
                            std::cout << "Введите элементы массива: ";
                            i = -1;
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
        for (int i = 0; i < m; i++) {
            int min = 2147483647;
            for (int i1 = 0; i1 <= n - 1; i1++) {
                if (array[i1][i] < min) {
                    min = array[i1][i];
                    column = i + 1;
                }
            }
            std::cout << "В столбце #" << column << " минимальный элемент: " << min << std::endl;
        }
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
}

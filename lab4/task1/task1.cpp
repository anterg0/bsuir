#include <iostream>

int main(){
    std::cout << "Цель задания: Найти кол-во пар инверсий внутри массива.\nВыполнил Шпаковский А.В.\nВариант 12.\n";
        while (true) {
            int n, count = 0;
            std::cout << "Введите кол-во элементов массива: ";
            std::cin >> n;
            if ( n <= 0 || (std::cin.peek() != '\n')) {
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
            int array[n];
            std::cout << "Введите элементы массива: ";
            for(int i = 0; i < n; i++) {
                std::cin >> array[i];
                if (std::cin.fail()) {
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
            for (int i = 0; i < n - 1; i++) {
                if (array[i] > array[i + 1]) count++;
            }
            std::cout << "Кол-во пар инверсий: " << count;
            std::cout << "\nДля повтора введите 'y', либо что угодно другое для завершения программы.\n";
            char a;
            std::cin >> a;
            switch(a) {
                case 'y':
                    continue;
                    break;
                default:
                    return 0;
                    break;
            }
        }
    }


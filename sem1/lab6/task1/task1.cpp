#include <iostream>

bool intValidation(char a) {
    if (a != '0' && a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8' && a != '9') return true;
    return false;
}

int main() {
    char bebra[1024]{};
    int i = 0;
    std::cout << "Дана строка символов, состоящая из цифр, разделенных пробелами. Вывести четные числа этой строки.\nВыполнил Шпаковский Антон.\nВариант 10.\n";
    while (true) {
        std::cout << "Введите строку, состоящую из цифр: ";
        while ((bebra[i] = getchar()) != '\n') {
            if (intValidation(bebra[i])) {
                std::cout << "Неверный ввод. Введи строку заново: ";
                std::cin.clear();
                std::cin.ignore(32676,'\n');
                i = 0;
                continue;
            }
            i++;
        }
        for (int j = 0; j < i;j++) if (!((int(bebra[j]) - '0') % 2)) std::cout << bebra[j] << " ";
        std::cout << "\nВведите 'f' для повтора программы или что-то другое для завершения ";
        char a = getchar();
        switch (a) {
            case 'f':
                std::cin.clear();
                std::cin.ignore(32676,'\n');
                continue;
            break;
            default:
                return 0;
            break;
            }
    }
}


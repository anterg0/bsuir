#include <iostream>

bool intValidation (char n) {
    if (n != '0' && n != '1' && n != '2' && n != '3' && n != '4' && n != '5' && n != '6' && n != '7' && n != '8' && n != '9') return true;
    return false;
}

int main() {
    std::cout << "В функции для каждой строки проверить, является она палиндромом (симметричной с точностью до пробелов) или нет. \nВыполнил Шпаковский Антон.\nВариант 10.\n";
    while (true) {
        std::cout << "Введите кол-во вводимых строк: ";
        char n = getchar();
        if (intValidation(n)) {
            std::cout << "Неверный ввод.\n";
            std::cin.clear();
            std::cin.ignore(32676,'\n');
            continue;
        }
        std::cin.clear();
        std::cin.ignore(32676,'\n');
        int rowCount = int(n) - '0';
        char input[rowCount][2049];
        for (int i = 0; i < rowCount; i++) {
            int j = 0;
                while (input[i][j - 1] != '\n') {
                input[i][j] = getchar();
                j++;
            }
        }
        for (int i = 0; i < rowCount; i++) {
            bool palindrom = true;
            int j = 0;
            int count = 0;
                while (input[i][j] != '\n') {
                count++;
                j++;
            }
                for (int k = 0; k < count; k++) {
                    if (input[i][k] != input[i][count - k - 1]) palindrom = false;
                }
                for (int k = 0; k < count; k++) {
                    std::cout << input[i][k];
                }
                std::cout << " " << (palindrom ? "YES" : "NO") << '\n';
            }
        std::cout << "Введите 'f' для повтора программы или что-то другое для завершения: ";
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

#include <iostream>

int main() {
    std::cout << "В тексте найти и вывести на экран все слова максимальной и минимальной длины.\nВыполнил Шпаковский Антон.\nВариант 10.\n";
    while (true) {
        char input[2049];
        int i = 0;
        int count = 0;
        int max = 0;
        int min = 10000000;
        std::cout << "Введите строку: ";
        while((input[i] = getchar()) != '\n') {
            if (input[i] == ' ') {
                if (count < min) min = count;
                count = 0;
            } else count++;
            i++;
        
            if (count > max) max = count;
        }
        std::cout << '\n';
        i = 0;
        count = 0;
        while (input[i - 1] != '\n') {
            if (input[i] == ' ' || input[i] == '\n') {
                if (count == min || count == max) {
                    for (int j = i - count; j < i; j++) std::cout << input[j];
                    std::cout << '\n';
                }
                count = 0;
            } else count++;
            i++;
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

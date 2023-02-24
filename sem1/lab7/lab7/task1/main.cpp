#include <iostream>
#include <cmath>

std::string binary(long long num) {
    long long num2 = abs(num);
    std::string s;
    while (true) {                      
        s += std::to_string(num2 % 2);
        num2 /= 2;
        if (num2 == 1 || num2 == 0) {
            s += std::to_string(num2);
            break;
        }
    }
    unsigned long size = s.size();
    if (num < 0) {
        if (size % 8 == 0) {
            std::reverse(s.begin(),s.end());
            return s;
        }
        else {
            int times = (size / 8) + 1;
            for (int i = 0; i < ((8 * times - 1) - size); i++) s += '0';
            s += '1';
        }
    }
    std::reverse(s.begin(),s.end());
    return s;
}

int main() {
    std::cout << "Перевести числа. Предусмотреть ввод положительных и отрицательных чисел.\nВариант 9. Перевод из естественной формы в прямой код.\nВыполнил Шпаковский Антон\n";
    long long n;
    std::cout << "Введите число: ";
    std::cin >> n;
    std::string n_binary = binary(n);
    std::cout << "'" << n << "' число в прямом коде: " << n_binary << "\n";
    return 0;
}

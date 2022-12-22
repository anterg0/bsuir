#include <iostream>
#include <cmath>
#include <algorithm>
int n1, n2;

std::string binary(int a);

std::string pryamoiCod(long long num);

std::string evenOut(std::string shortstring, long shortlength, long longlength);

std::string sum(int n1, int n2);

int toDecimal(std::string bruh);

int main() {
    std::cout << "Задание: Осуществить сложение чисел. Разработать функции для выполнения операции сложения. Предусмотреть ввод положительных и отрицательных чисел. Найдите сумму двоичных чисел, заданных в естественной форме. Сложение выполните в дополнительном коде. Ответ выразите в прямом коде.\nВыполнил Шпаковский Антон.\n";
    while (true) {
        while (true) {
            std::cin >> n1 >> n2;
            if (std::cin.fail()) {
                std::cout << "Неверный ввод. Повторите снова.\n";
                std::cin.clear();
                std::cin.ignore(32676,'\n');
                continue;
            } else break;
        }
        std::string bruh = sum(n1, n2);
        long long decimal = toDecimal(bruh);
        bruh = pryamoiCod(decimal);
        std::cout << bruh << "\n";
        std::cout << "Желаете повторить? (y/n)";
        char bebra;
        std::cin >> bebra;
        switch (bebra) {
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

std::string binary(int a) {
    std::string result;
    int b = a;
    if (a < 0) b = -a;
    while (b) {
        result += std::to_string(b % 2);
        b /= 2;
    }
    if (a < 0) {
        for (int i = 0; i < result.size();i++) {
            if (result[i] == '0') result[i] = '1';
            else if (result[i] == '1') result[i] = '0';
        }
        result += '1';
        std::string result2 = result;
        std::reverse(result2.begin(), result2.end());
        result = sum(toDecimal(result2), 1);
        return result;
    }
    if (result.size() % 8 != 0) {
        if (result.size() < 8) {
            int diff = 8 - result.size();
            for (int i = result.size();diff;i++) {
                result.push_back('0');
                diff--;
            }
        }
        else {
            int diff = 8 - (result.size() % 8);
            for (long i = result.size();diff;i++) {
                result.push_back('0');
                diff--;
            }
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string pryamoiCod(long long num) {
    long long num2 = abs(num);
    std::string s;
    while (true) {                      // O(log num2)
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

std::string evenOut(std::string shortstring, long shortlength, long longlength) {
    std::string result;
    std::reverse(shortstring.begin(),shortstring.end());
    result = shortstring;
    long diff = longlength - shortlength;
    for (int i = 0; i < diff; i++) result += '0';
    std::reverse(result.begin(), result.end());
    return result;
}

std::string sum(int n1, int n2) {
    std::string result, a = binary(n1), b = binary(n2);
    if (a.length() < b.length()) a = evenOut(a, a.length(), b.length());
    if (b.length() < a.length()) b = evenOut(a, b.length(), a.length());
    int carry = 0;
    for (long i = a.length() - 1; i >= 0; i--) {
        if (!(carry)) {
            if (a[i] == '0' && b[i] == '0') result += '0';
            else if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) result += '1';
            else if (a[i] == '1' && b[i] == '1') {
                result += '0';
                carry = 1;
            }
        }
        else {
            if (a[i] == '0' && b[i] == '0') {
                result += '1';
                carry = 0;
            }
            else if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) {
                result += '0';
                carry = 1;
            }
            else if (a[i] == '1' && b[i] == '1') {
                result += '1';
                carry = 1;
            }
        }
    }
    if (carry) result += '1';
    std::reverse(result.begin(), result.end());
    return result;
}

int toDecimal(std::string bruh) {
    int result = 0;
    for (int i = 0; i < bruh.size(); i++) {
        if (bruh[i] == '0') bruh.erase(i,1);
        if (bruh[i] == '1') break;
    }
    std::reverse(bruh.begin(),bruh.end());
    for (int i = 0; i < bruh.length(); i++) {
        result += (int)pow(2, i) * (bruh[i] - '0');
    }
    return result;
}

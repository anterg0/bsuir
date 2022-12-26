#include <iostream>
#include <cmath>
#include <algorithm>

void task();

std::string sumInBase(std::string a, std::string b, int base);

std::string subtrInBase(std::string a, std::string b, int base);

std::string evenOut(std::string shortstring, long shortlength, long longlength);

std::string convertToAnyBase(int n, int base);

int main() {
    std::cout << "Задание: Пользователь вводит основание системы счисления. Осуществить сложение и вычитание чисел в заданной системе счисления. В другую систему счисления не переводить. В системах счисления больших десятичной использовать буквы по аналогии с шестнадцатеричной системой. Разработать функции для выполнения операции сложения и функции для выполнения операции вычитания. Предусмотреть ввод положительных и отрицательных чисел.\nВыполнил Шпаковский Антон.\n";
    task();
    return 0;
}

void task() {
    int base;
    std::string n1, n2;
    while (true) {
        std::cout << "Введите первое число, второе число и основание системы счисления (пр. 123 123 16): ";
        std::cin >> n1 >> n2 >> base;
        if (std::cin.fail() || base < 2 || base > 36) {
            std::cout << "Неверный ввод. Повторите снова.\n";
            std::cin.clear();
            std::cin.ignore(32676,'\n');
            continue;
        } else break;
    }
    /* if (n1 < 0 && n2 >= 0) {
        if (abs(n1) >= n2) {
            std::string bebra1 = convertToAnyBase(-n1, base), bebra2 = convertToAnyBase(n2, base);
            std::string bebraSum = subtrInBase(bebra1, bebra2, base);
            std::string bebraSubtr = sumInBase(bebra1, bebra2, base);
            std::cout << "Cумма данных чисел: -" << bebraSum << "\nРазность данных чисел: -" << bebraSubtr;
        }
        else {
            std::string bebra1 = convertToAnyBase(-n1, base), bebra2 = convertToAnyBase(n2, base);
            std::string bebraSum = subtrInBase(bebra2, bebra1, base);
            std::string bebraSubtr = sumInBase(bebra1, bebra2, base);
            std::cout << "Cумма данных чисел: " << bebraSum << "\nРазность данных чисел: -" << bebraSubtr;
        }
    } else if (n1 < 0 && n2 < 0) {
        if (abs(n1) < abs(n2)) {
            std::string bebra1 = convertToAnyBase(-n1, base), bebra2 = convertToAnyBase(-n2, base);
            std::string bebraSum = sumInBase(bebra2, bebra1, base);
            std::string bebraSubtr = subtrInBase(bebra2, bebra1, base);
            std::cout << "Cумма данных чисел: -" << bebraSum << "\nРазность данных чисел: " << bebraSubtr;
        }
        else if (abs(n1) >= abs(n2)) {
            std::string bebra1 = convertToAnyBase(-n1, base), bebra2 = convertToAnyBase(-n2, base);
            std::string bebraSum = sumInBase(bebra2, bebra1, base);
            std::string bebraSubtr = subtrInBase(bebra1, bebra2, base);
            std::cout << "Cумма данных чисел: -" << bebraSum << "\nРазность данных чисел: -" << bebraSubtr;
        }
    } else if (n1 >= 0 && n2 < 0) {
        if (n1 >= abs(n2)) {
            std::string bebra1 = convertToAnyBase(n1, base), bebra2 = convertToAnyBase(-n2, base);
            std::string bebraSum = subtrInBase(bebra1, bebra2, base);
            std::string bebraSubtr = sumInBase(bebra1, bebra2, base);
            std::cout << "Cумма данных чисел: " << bebraSum << "\nРазность данных чисел: " << bebraSubtr;
        }
        else {
            std::string bebra1 = convertToAnyBase(n1, base), bebra2 = convertToAnyBase(-n2, base);
            std::string bebraSum = subtrInBase(bebra2, bebra1, base);
            std::string bebraSubtr = sumInBase(bebra1, bebra2, base);
            std::cout << "Cумма данных чисел: -" << bebraSum << "\nРазность данных чисел: " << bebraSubtr;
        }
    } else { */
        std::string bebra1 = n1, /* convertToAnyBase(n1, base), */ bebra2 = n2; // convertToAnyBase(n2, base);
        std::string bebraSum = sumInBase(bebra2, bebra1, base);
        std::string bebraSubtr;
        if (n1 >= n2) {
            bebraSubtr = subtrInBase(bebra1, bebra2, base);
            std::cout << "Cумма данных чисел: " << bebraSum << "\nРазность данных чисел: " << bebraSubtr;
        }
        else {
            bebraSubtr = subtrInBase(bebra2, bebra1, base);
            std::cout << "Cумма данных чисел: " << bebraSum << "\nРазность данных чисел: -" << bebraSubtr;
        }
 //   }
}

std::string convertToAnyBase(int n, int base) {
    std::string result;
    if (base < 10) {
        while (n) {
            result += std::to_string(n % base);
            n /= base;
        }
        std::reverse(result.begin(),result.end());
        return result;
    }
    else if (base <= 36) {
        const char symbols[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int leftout;
        while (n) {
            leftout = n % base;
            result += symbols[leftout];
            n /= base;
        }
        std::reverse(result.begin(),result.end());
        return result;
    }
    return 0;
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

std::string sumInBase(std::string a, std::string b, int base) {
    std::string result;
    std::string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (a.length() < b.length()) a = evenOut(a, a.length(), b.length());
    if (b.length() < a.length()) b = evenOut(b, b.length(), a.length());
    int bruh = 0;
    for (int i = a.length() - 1; i >= 0;i--) {
        bruh += (symbols.find(a[i]) + symbols.find(b[i]));
        result += symbols[bruh % base];
        bruh /= base;
        if (bruh != 0 && i == 0) result += symbols[bruh % base];
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string subtrInBase(std::string a, std::string b, int base) {
    std::string result;
    std::string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (a.length() < b.length()) a = evenOut(a, a.length(), b.length());
    if (b.length() < a.length()) b = evenOut(b, b.length(), a.length());
    int bruh = 0,carry = 0;
    for (int i = a.length() - 1; i >= 0; i--) {
        bruh = symbols.find(a[i]) - symbols.find(b[i]) + carry;
        if (bruh < 0) {
            carry = -1;
            bruh += base;
        }
        else carry = 0;
        result += symbols[bruh];
    }
    std::reverse(result.begin(), result.end());
    return result;
}

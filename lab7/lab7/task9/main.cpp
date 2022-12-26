#include <iostream>
#include <algorithm>

std::string base3(int num);

std::string evenOut(std::string s);

int main() {
    int poisoned_barrel;
    std::string slaves = "DDDDD", bebra;
    int deadinside[] = {0,0,0,0,0};
    std::cout << "Введите номер отравленной бочки: ";
    while (true) {
        std::cin >> poisoned_barrel;
        if (std::cin.fail() || poisoned_barrel > 240 || poisoned_barrel <= 0) {
            std::cout << "Неправильно, попробуй ещё раз: ";
            std::cin.clear();
            std::cin.ignore(32676,'\n');
        }
        else break;
    }
    for (int i = 0; i < 241; i++) {
        bebra = base3(i);
        for (int j = 0; j < 5; j++) {
            if (bebra[j] == '1' && poisoned_barrel == i) {
                slaves[j] = '1';
                deadinside[j] = 1;
            }
        }
    }
    for (int i = 0; i < 241; i++) {
        bebra = base3(i);
        for (int j = 0; j < 5; j++) {
            if (bebra[j] == '2' && poisoned_barrel == i && deadinside[j] != 1) {
                slaves[j] = '2';
            }
        }
    }
    std::cout << slaves << '\n';
    for (int i = 0; i < 5; i++) if (slaves[i] == 'D') slaves[i] = '0';
    int barrel = (slaves[0] - 48) * 81 + (slaves[1] - 48) * 27 + (slaves[2] - 48) * 9 + (slaves[3] - 48) * 3 + (slaves[4] - 48);
    std::cout << "Номер отравленной бочки: " << barrel << '\n';
    return 0;
}

std::string base3(int num) {
    std::string result;
    while (num) {
        result += std::to_string(num % 3);
        num /= 3;
    }
    std::reverse(result.begin(), result.end());
    result = evenOut(result);
    return result;
}

std::string evenOut(std::string s) {
    while (s.length() < 5) s.insert(0, 1, '0');
    return s;
}

#include <iostream>
#include <cmath>

std::string bebra(std::string s) {
    std::string result;
    bool bebra = false;
    for (int i = 0; i < s.size();i++) if (isalpha(s[i])) return 0;
    for (int i = 0; i < s.size();i++) {
        if (s.size() == 1) {
            if (s[i] == '1') result = "I";
            if (s[i] == '2') result = "II";
            if (s[i] == '3') result = "III";
            if (s[i] == '4') result = "IV";
            if (s[i] == '5') result = "V";
            if (s[i] == '6') result = "VI";
            if (s[i] == '7') result = "VII";
            if (s[i] == '8') result = "VIII";
            if (s[i] == '9') result = "IX";
        }
        else if (s.size() == 2){
            if (i > 0) {
                if (s[i] == '1') result += "I";
                if (s[i] == '2') result += "II";
                if (s[i] == '3') result += "III";
                if (s[i] == '4') result += "IV";
                if (s[i] == '5') result += "V";
                if (s[i] == '6') result += "VI";
                if (s[i] == '7') result += "VII";
                if (s[i] == '8') result += "VIII";
                if (s[i] == '9') result += "IX";
            }
            else if (i == 0) {
                if (s[i] == '1') result += "X";
                if (s[i] == '2') result += "XX";
                if (s[i] == '3') result += "XXX";
                if (s[i] == '4') result += "XL";
                if (s[i] == '5') result += "L";
                if (s[i] == '6') result += "LX";
                if (s[i] == '7') result += "LXX";
                if (s[i] == '8') result += "LXXX";
                if (s[i] == '9') result += "XC";
            }
        }
        else if (s.size() == 3) {
            if (i == 0) {
                if (s[i] == '1') result += "C";
                if (s[i] == '2') result += "CC";
                if (s[i] == '3') result += "CCC";
                if (s[i] == '4') result += "CD";
                if (s[i] == '5') result += "D";
                if (s[i] == '6') result += "DC";
                if (s[i] == '7') result += "DCC";
                if (s[i] == '8') result += "DCCC";
                if (s[i] == '9') result += "CM";
            }
            if (i == 1) {
                if (s[i] == '1') result += "X";
                if (s[i] == '2') result += "XX";
                if (s[i] == '3') result += "XXX";
                if (s[i] == '4') result += "XL";
                if (s[i] == '5') result += "L";
                if (s[i] == '6') result += "LX";
                if (s[i] == '7') result += "LXX";
                if (s[i] == '8') result += "LXXX";
                if (s[i] == '9') result += "XC";
            }
            if (i == 2) {
                if (s[i] == '1') result += "I";
                if (s[i] == '2') result += "II";
                if (s[i] == '3') result += "III";
                if (s[i] == '4') result += "IV";
                if (s[i] == '5') result += "V";
                if (s[i] == '6') result += "VI";
                if (s[i] == '7') result += "VII";
                if (s[i] == '8') result += "VIII";
                if (s[i] == '9') result += "IX";
            }
        }
        else if (s.size() >= 4) {
            if (!(bebra)) {
                for (int j = 0; j < int(std::stoll(s) / (pow(10, s.size() - (s.size() - 3))));j++) result += "M";
                bebra = true;
            }
            if (s.size() - i == 3) {
                if (s[i] == '1') result += "C";
                if (s[i] == '2') result += "CC";
                if (s[i] == '3') result += "CCC";
                if (s[i] == '4') result += "CD";
                if (s[i] == '5') result += "D";
                if (s[i] == '6') result += "DC";
                if (s[i] == '7') result += "DCC";
                if (s[i] == '8') result += "DCCC";
                if (s[i] == '9') result += "CM";
            }
            if (s.size() - i == 2) {
                if (s[i] == '1') result += "X";
                if (s[i] == '2') result += "XX";
                if (s[i] == '3') result += "XXX";
                if (s[i] == '4') result += "XL";
                if (s[i] == '5') result += "L";
                if (s[i] == '6') result += "LX";
                if (s[i] == '7') result += "LXX";
                if (s[i] == '8') result += "LXXX";
                if (s[i] == '9') result += "XC";
            }
            if (s.size() - i == 1) {
                if (s[i] == '1') result += "I";
                if (s[i] == '2') result += "II";
                if (s[i] == '3') result += "III";
                if (s[i] == '4') result += "IV";
                if (s[i] == '5') result += "V";
                if (s[i] == '6') result += "VI";
                if (s[i] == '7') result += "VII";
                if (s[i] == '8') result += "VIII";
                if (s[i] == '9') result += "IX";
            }
        }
    }
    return result;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << bebra(s);
    return 0;
}

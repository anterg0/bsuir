#include <iostream>

long long answer(std::string s) {
    bool palindrom = true;
    bool allCharsEqual = true;
    char bebra = s[0];
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - i - 1]) {
            palindrom = false;
            break;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != bebra) {
            allCharsEqual = false;
            break;
        }
    }
    if (palindrom && !(allCharsEqual)) return s.size() - 1;
    else if (palindrom && allCharsEqual) return -1;
    else return s.size();
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << answer(s);
    return 0;
}

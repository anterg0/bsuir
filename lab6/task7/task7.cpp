#include <iostream>

int main() {
    std::string s;
    std::getline(std::cin, s);
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
    if (palindrom && !(allCharsEqual)) std::cout << s.size() - 1;
    else if (palindrom && allCharsEqual) std::cout << "-1";
    else std::cout << s.size();
    return 0;
}


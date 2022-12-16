#include <iostream>

std::string answer(std::string &s, std::string &t) {
    std::string bebra;
    int flag = 0;
    for (int m = 0; m < s.size(); m++) {
        bebra = s[m];
        if (bebra == t) {
            flag = 1;
            break;
        }
        for (int j = m + 1; j < s.size();j++) {
            bebra += s[j];
            if (bebra == t) {
                flag = 1;
                break;
            }
            std::string bebra2 = bebra,bebra3;
            bebra3 += s[m];
            for (int u = j - 2; u > -1; u--) {
                bebra3 += s[u];
                if (bebra3 == t) {
                    flag = 1;
                    break;
                }
                if (flag) break;
            }
            for (int u = j - 1; u > -1; u--) {
                bebra2 += s[u];
                if (bebra2 == t || bebra3 == t) {
                    flag = 1;
                    break;
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) break;
    }
    if (!(flag)) return "NO\n";
    else return "YES\n";
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n;i++) {
        std::string s,t;
        std::cin >> s;
        std::cin >> t;
        std::cout << answer(s, t);
    }
    return 0;
}



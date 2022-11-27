#include <iostream>

int main() {
    std::string a;
    std::getline(std::cin, a);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 'c')
            if (a[i + 1] == 'e' || a[i + 1] == 'i' || a[i + 1] == 'y') {
                a[i] = 's';
            } else a[i] = 'k';
 
        if (a[i] == 'C')
            if (a[i + 1] == 'e' || a[i + 1] == 'i' || a[i + 1] == 'y') {
                a[i] = 'S';
            } else a[i] = 'K';

        if (a[i] == 'q' && a[i + 1] == 'u') {
            a[i] = 'k';
            a[i + 1] = 'v';
        } else if (a[i] == 'q') a[i] = 'k';
        if (a[i] == 'Q' && a[i + 1] == 'u') {
            a[i] = 'K';
            a[i + 1] = 'v';
        } else if (a[i] == 'Q' && a[i + 1] == 'U') {
            a[i] = 'K';
            a[i + 1] = 'V';
        } else if (a[i] == 'Q') a[i] = 'K';
        if (a[i] == 'x') a.replace(i, 1, "ks");
        if (a[i] == 'X') a.replace(i, 1, "Ks");
        if (a[i] == 'w') a[i] = 'v';
        if (a[i] == 'W') a[i] = 'V';
        if (a[i] == 'p' && a[i + 1] == 'h') a.replace(i, 2, "f");
        if (a[i] == 'P' && a[i + 1] == 'h') a.replace(i, 2, "F");
        if (i + 2 <= a.size() - 1)
            if (a[i] == 'y' && a[i + 1] == 'o' && a[i + 2] == 'u') a.replace(i, 3, "u");
        if (i + 2 <= a.size() - 1)
            if (a[i] == 'Y' && a[i + 1] == 'o' && a[i + 2] == 'u') a.replace(i, 3, "U");
        if (a[i] == 'o' && a[i + 1] == 'o') a.replace(i, 2, "u");
        if (a[i] == 'O' && a[i + 1] == 'o') a.replace(i, 2, "U");
        if (a[i] == 'e' && a[i + 1] == 'e') a.replace(i, 2, "i");
        if (a[i] == 'E' && a[i + 1] == 'e') a.replace(i, 2, "I");
        if (a[i] == 't' && a[i + 1] == 'h') a.replace(i, 2, "z");
        if (a[i] == 'T' && a[i + 1] == 'h') a.replace(i, 2, "Z");
    }
    for (int i = 0; i < a.size(); i++) {
            if (a[i + 1] == a[i] && !(a[i] == 'E' || a[i] == 'Y' || a[i] == 'U' || a[i] == 'I' || a[i] == 'O' || a[i] == 'A' || a[i] == 'e' || a[i] == 'y' || a[i] == 'u' || a[i] == 'i' || a[i] == 'o' || a[i] == 'a')) {
                a.erase(i + 1, 1);
                i--;
            }
            else if (char(a[i + 1] - 'A' + 'a') == a[i] && !(a[i] == 'E' || a[i] == 'Y' || a[i] == 'U' || a[i] == 'I' || a[i] == 'O' || a[i] == 'A' || a[i] == 'e' || a[i] == 'y' || a[i] == 'u' || a[i] == 'i' || a[i] == 'o' || a[i] == 'a')) {
                a.erase(i + 1, 1);
                i--;
            }
            else if (char(a[i] - 'a' + 'A') == a[i + 1] && !(a[i] == 'E' || a[i] == 'Y' || a[i] == 'U' || a[i] == 'I' || a[i] == 'O' || a[i] == 'A' || a[i] == 'e' || a[i] == 'y' || a[i] == 'u' || a[i] == 'i' || a[i] == 'o' || a[i] == 'a')) {
                a.erase(i + 1, 1);
                i--;
            }
        }
    std::cout << a;
    return 0;
}
//if ((char(a[i] - 'A' + 'a') == a[i + 1]) && !(a[i] =='E' || a[i] =='Y' || a[i] =='U' || a[i] =='I' || a[i] =='O' || a[i] =='A')) a.erase(i + 1, 1);
//if ((a[i] == a[i + 1]) && !(a[i] == 'e' || a[i] == 'y' || a[i] == 'u' || a[i] == 'i' || a[i] == 'o' || a[i] == 'a')) a.erase(i + 1, 1);
//if ((char(a[i + 1] - 'A' + 'a') == a[i]) && !(a[i] == 'e' || a[i] == 'y' || a[i] == 'u' || a[i] == 'i' || a[i] == 'o' || a[i] == 'a')) a.erase(i + 1, 1);


#include <iostream>

int count(std::string n){
    int res = 0;
    int numbers[10]{};
    int bruh[n.size()];
    for (int i = 0; i < n.size(); i++) {
        bruh[i] = n[i] - '0';
    }
    for (int i = 0; i < n.size(); i++) {
        numbers[bruh[i]]++;
    }
    for (int i = 0; i < 10; i++) {
        if (numbers[i] ) res++;
    }
    return res;
}


int main() {
    std::string s;
    int i,number;
    std::cin >> s >> i;
    int size = s.size();
        char num[s.size()];
    for (int m = size - 1, j = 0; m != -1; m--,j++) {
        num[j] = s[m];
    }
    char bebrochka[s.size()];
    for (int j = 0; j < s.size(); j++) {
        bebrochka[j] = s[j];
    }
    number = bebrochka[i - 1] - '0';
    std::cout << count(s) << "\n";
    for (int j = 0; j < s.size(); j++) {
        if ((num[j] - '0') == number) std::cout << j << " ";
    }
    return 0;
}

#include <iostream>
#include <cstring>

long long factorial(long long a) {
    if (a > 1) return a * factorial(a - 1);
    return 1;
}

long long answer (char* bebra) {
    int alpha[26]{};
    long long result = factorial(strlen(bebra));
    for (int i = 0; i < strlen(bebra); i++) {
        if (islower(bebra[i])) bebra[i] = toupper(bebra[i]);
        alpha[int(bebra[i]) - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        result /= factorial(alpha[i]);
    }
    return result;
}

int main() {
    char bebra[15];
    std::cin >> bebra;
    long long result = answer(bebra);
    std::cout << result;
    return 0;
}


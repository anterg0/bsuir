#include <iostream>
#include <cstring>
int alpha[26]{};
char bebra[15];

long long factorial(long long a) {
    if (a > 1) return a * factorial(a - 1);
    return 1;
}

void answer () {
    long long result = factorial(strlen(bebra));
    for (int i = 0; i < 26; i++) {
        result /= factorial(alpha[i]);
    }
    std::cout << result;
}

int main() {
    std::cin >> bebra;
    for (int i = 0; i < strlen(bebra); i++) {
        if (islower(bebra[i])) bebra[i] = toupper(bebra[i]);
        alpha[int(bebra[i]) - 'A']++;
    }
    answer();
    return 0;
}

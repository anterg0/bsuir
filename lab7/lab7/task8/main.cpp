#include <iostream>
#include <cmath>
#include <algorithm>

std::string convertTo3(long long num) {
    std::string result;
    std::string numbers = "0123";
    while (num) { // O(log num)
        result += std::to_string(num % 3);
        num /= 3;
    }
    std::reverse(result.begin(), result.end());
    for (int j = 0; j < 20; j++) {
        for (int i = result.length() - 1; i >= 0; i--) {
            if (result[i] == '0' && result[i - 1] == '1') {
                result[i] = '3';
                result[i - 1] = '0';
                i++;
                continue;
            } else if (result[i] == '0' && result[i - 1] == '2') {
                result[i] = '3';
                result[i - 1] = '1';
                i++;
                continue;
            } else if (result[i] == '0' && result[i - 1] == '3') {
                result[i] = '3';
                result[i - 1] = '2';
                i++;
                continue;
            }
        }
    }
    for (int i = 0; i < result.length(); i++) {
        if (result[i] == '0') result.erase(i,1);
        else break;
    }
    return result;
}

int main() {
    long long num;
    std::cin >> num;
    std::string bebra = convertTo3(num);
    std::cout << bebra;
    
    return 0;
}

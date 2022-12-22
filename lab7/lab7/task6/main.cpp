#include <iostream>

int summa(int num1, int num2) {
    int res = 0, carry = 0;
    res = num1 ^ num2;
    carry = (num1 & num2) << 1;
    while (carry) {
        int tmp = res;
        res = res ^ carry;
        carry = (tmp & carry) << 1;
    }
    return res;
}

int negative(int n) {
    return summa(~n, 1);
}

int subtraction(int a, int b) {
    return summa(a, negative(b));
}

int getSign(int n) {
    return n >> 31;
}

int positive(int n) {
    return (getSign(n) & 1) ? negative(n) : n;
}

int multiply(int a, int b) {
    bool isnegative = false;
    if (getSign(a) ^ getSign(b))
        isnegative = true;
    a = positive(a);
    b = positive(b);
    int res = 0;
    while (b | 0) {
        if (b & 1)
            res = summa(res, a);
        a = a << 1;
        b = b >> 1;
    }
    return isnegative == true ? negative(res) : res;
}


int division(int a, int b) {
    bool isnegative = false;
    if (getSign(a) ^ getSign(b))
        isnegative = true;

    a = positive(a);
    b = positive(b);

    int res = 0;
    while (a >= b) {
        res = summa(res, 1);
        a = subtraction(a, b);
    }
    return isnegative == true ? negative(res) : res;
}

int mod(int a, int b) {
    int r = division(a, b);
    return subtraction(a, multiply(r, b));
}

int main() {
    int bebra;
    std::cin >> bebra;
    std::cout << mod(bebra, 7);
    return 0;
}

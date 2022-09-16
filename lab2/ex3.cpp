#include <iostream>

int main() {
    long int X,Y;
    long double A,B,C,K;
    std::cin >> X >> Y >> A >> B >> C >> K;
    if (X < Y) {
        X = 0;
    }
    else if (Y < X) {
        Y = 0;
    }
    else if (X == Y) {
        X = 0;
        Y = 0;
    }
    
    if (A > B && A > C) {
        A = A - K;
    }
    else if (B > A && B > C) {
        B = B - K;
    }
    else if (C > A && C > B) {
        C = C - K;
    }
    
    std::cout << X << " " << Y << "\n" << A << " " << B << " " << C;
    return 0;
}

#include <iostream>
#include <cmath>

int main() {
    double A,D,x,b,S,U,B,K,p,C,n,Q,y,z,T,m,h,Y,d,k;
    std::cin >> x >> D >> p >> K >> C >> n >> y >> z >> m >> h >> d >> k;
    // #1
    b = x + D;
    A = D * x / b;
    S = (pow(A,2) + b * cos(x)) / (pow(D,3) + (A + D - b));
    std::cout << S << "\n";
    // #2
    A = x + sin(p);
    B = exp(K);
    U = 1 + (pow(K,2) / (2 * A * B)) - B + D * C;
    std::cout << U << "\n";
    // #3
    B = cos(x);
    C = p - n;
    Q = (pow(B,2) / (K * D)) + B * pow(C,3);
    std::cout << Q << "\n";
    // #4
    A = x - y;
    B = sqrt(z);
    T = cos(x) + (pow(A,2) / (K - C * D)) - B;
    std::cout << T << "\n";
    // #5
    A = fabs(n + m);
    D = tan(x);
    U = 1.29 + (K / A) + pow(D,2);
    std::cout << U << "\n";
    // #6
    A = x + y;
    D = fabs(C - A);
    S = 10.1 + (A / C) + (D / pow(K,2));
    std::cout << S << "\n";
    // #7
    A = x - p;
    B = log(h);
    Y = 0.78 * B + (pow(A, 3) / (K * C * D));
    std::cout << Y << "\n";
    // #8
    A = log10(x);
    B = x + exp(d);
    Y = (A + B) - (pow(C, 2) / K);
    std::cout << Y << "\n";
    // #9
    A = sin(x) - z;
    B = fabs(p - x);
    Y = pow(A + B, 2) - (K / (C * D));
    std::cout << Y << "\n";
    // #10
    A = log(x) - k;
    B = sqrt(z);
    Y = pow(D, 2) + (pow(C, 2) / (0.75 * A)) + B;
    std::cout << Y << "\n";
    return 0;
}

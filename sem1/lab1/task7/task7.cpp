#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    long double x1, y1, x2, y2, x3, y3;
    long double AB,AC,BC,h_AB,h_BC,h_AC,m_AB,m_BC,m_AC,b_AB,b_BC,b_AC,S1,S2,S3,P,p,r,R,C_R,C_r,S_R,S_r;
    long double alpha_rad,beta_rad,gamma_rad,alpha_deg,beta_deg,gamma_deg;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    // Нахождение длин всех сторон
    AB = sqrt(pow((y2 - y1), 2) + pow((x2-x1), 2));
    BC = sqrt(pow((y3 - y2), 2) + pow((x3-x2), 2));
    AC = sqrt(pow((y3 - y1), 2) + pow((x3-x1), 2));
    // Периметр и полупериметр
    P = AB + BC + AC;
    p = P / 2;
    // Нахождение всех высот, медиан и биссектрис
    h_AB = 2 * sqrt(p * (p - AB) * (p - BC) * (p - AC)) / AB;
    h_BC = 2 * sqrt(p * (p - AB) * (p - BC) * (p - AC)) / BC;
    h_AC = 2 * sqrt(p * (p - AB) * (p - BC) * (p - AC)) / AC;
    m_AB = sqrt((2 * AC * AC) + (2 * BC * BC) - (AB * AB)) / 2;
    m_BC = sqrt((2 * AB * AB) + (2 * AC * AC) - (BC * BC)) / 2;
    m_AC = sqrt((2 * AB * AB) + (2 * BC * BC) - (AC * AC)) / 2;
    b_AB = sqrt(AC * BC * (AB + BC + AC) * (AC + BC - AB)) / (AC + BC);
    b_BC = sqrt (AB * AC * (AB + BC + AC) * (AC + AB - BC)) / (AC + AB);
    b_AC = sqrt (AB * BC * (AB + BC + AC) * (AB + BC - AC)) / (AB + BC);
    // Радиусы вписанной и описанной окружностей
    r = sqrt((p - AB) * (p - BC) * (p - AC) / p);
    R = (AB * BC * AC) / (4 * sqrt(p * (p - AB) * (p - BC) * (p - AC)));
    // Нахождение углов
    alpha_rad = acos(((AB * AB) + (AC * AC) - (BC * BC)) / (2 * AB * AC));
    beta_rad = acos(((AB * AB) + (BC * BC) - (AC * AC)) / (2 * AB * BC));
    gamma_rad = acos(((BC * BC) + (AC * AC) - (AB * AB)) / (2 * BC * AC));
    alpha_deg = alpha_rad * 180 / M_PI;
    beta_deg = beta_rad * 180 / M_PI;
    gamma_deg = gamma_rad * 180 / M_PI;
    // Нахождение площади разными способами
    S1 = sqrt(p * (p - AB) * (p - BC) * (p - AC)) ;
    S2 = (AB * h_AB) / 2;
    S3 = (AB * AC * sin(alpha_rad)) / 2;
    // Длина и площадь описанной и вписанной окружностей
    C_R = 2 * M_PI * R;
    C_r = 2 * M_PI * r;
    S_R = M_PI * R * R;
    S_r = M_PI * r * r;
    std::cout << std::setprecision(5) << AB << "\n" << BC << "\n" << AC << "\n" << h_AB << "\n" << h_BC << "\n" << h_AC << "\n" << m_AB << "\n" << m_BC << "\n" << m_AC << "\n" << b_AB << "\n" << b_BC << "\n" << b_AC << "\n" << alpha_rad << " " << alpha_deg << "\n" << beta_rad << " " << beta_deg << "\n" << gamma_rad << " " <<  gamma_deg << "\n" << R << "\n" << r << "\n" << C_r << "\n" << S_r << "\n" << C_R << "\n" << S_R << "\n";
    std::cout << "Square of triangle " << S1 << " or " << S2 << " or " << S3 << "\n" << P;
    return 0;
}

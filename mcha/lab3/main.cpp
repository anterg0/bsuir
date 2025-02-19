#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;
#define MAX_ITERATIONS 1000
struct Result {
    double rootOfEq;
    int iterations;

    Result(double root = 0, int iterations = 0) {
        this->rootOfEq = root;
        this->iterations = iterations;
    }
};
struct Segment {
    double a;
    double b;

    Segment(double a = 0, double b = 0) {
        this->a = a;
        this->b = b;
    }
};
class Polynomial {
private:
    double a;
    double b;
    double c;
    double f0(double x) {			//Задание 1
        return pow(x, 3) + a * pow(x, 2) + b * x + c;
    }
    double f1(double x) {
        return 3 * pow(x, 2) + 2 * a * x + b;
    }
    double f2(double x) {			//Задание 2
        return ((2.0 / 9.0) * pow(a, 2) * x - (2.0 / 3.0) * b * x + (1.0 / 9.0) * a * b - c);
    }
    double f3(double x) {			//Задание 3
        double numerator = 4 * pow(a, 3) * c - pow(a * b, 2) - 18 * a * b * c + 4 * pow(b, 3) + 27 * pow(c, 2);
        double denominator = pow(a * a - 3 * b, 2);
        return -(9.0 / 4.0) * (numerator / denominator);
    }
    //Определение количества корней
    int N(double x) {
        vector<double> val(4);
        val[0] = f0(x);
        val[1] = f1(x);
        val[2] = f2(x);
        val[3] = f3(x);

        int count = 0;

        for (int i = 0; i < 3; i++)
            if (val[i] * val[i + 1] < 0)
                ++count;

        return count;
    }
public:
    Polynomial(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    int number_of_roots(Segment segment) {
        return N(segment.a) - N(segment.b);
    }
    vector<Segment> segment_with_roots(Segment segment, double step) { //отрезки на которых функция меняет знак
        vector<Segment> segments;

        for (double x = segment.a; x < segment.b; x += step)
            if (f0(x) * f0(x + step) < 0)
                segments.emplace_back(x, x + step);

        vector<Segment> upd_segments;
        for (int i = 0; i < segments.size(); i++) {

            if (number_of_roots(segments[i]) != 1)
                for (const auto& item : segment_with_roots(segments[i], step / 2))
                    upd_segments.push_back(item);
            else
                upd_segments.push_back(segments[i]);
        }
        return upd_segments;
    }
    Result half_division(Segment segment, double eps) { //метод половинного деления

        if (!(f0(segment.a) * f0(segment.b) < 0) ||		// f(a) * f(b) меньше нуля
            number_of_roots(segment) != 1)					// только 1 корень на промежутке
            return Result(-1, -1);

        int iterations = 1;

        double left = segment.a;
        double right = segment.b;
        double middle = (left + right) / 2;
        while (abs(f0(middle)) > eps && iterations < MAX_ITERATIONS) {
            if (f0(left) * f0(middle) < 0)
                right = middle;
            else
                left = middle;
            middle = (left + right) / 2;
            ++iterations;
        }
        return Result(middle, iterations);
    }

    Result chord_method(Segment segment, double eps) { //метод хорд
        if (!(f0(segment.a) * f0(segment.b) < 0) ||		// f(a) * f(b) меньше нуля
            number_of_roots(segment) != 1)					// только 1 корень на промежутке
            return Result(-1, -1);
        int iterations = 1;
        double Xn_prev = 0;
        double Xn_curr = 0;
        if (f0(segment.b) * (2 * a + 6 * segment.b) > 0) { //выпуклая
            Xn_prev = segment.a;
            Xn_curr = Xn_prev - (f0(Xn_prev) / (f0(segment.b) - f0(Xn_prev))) * (segment.b - Xn_prev);
            while (fabs(Xn_curr - Xn_prev) > eps && iterations < MAX_ITERATIONS) {
                Xn_prev = Xn_curr;
                Xn_curr = Xn_prev - (f0(Xn_prev) / (f0(segment.b) - f0(Xn_prev))) * (segment.b - Xn_prev);
                ++iterations;
            }
        }
        else { //вогнута
            Xn_prev = segment.b;
            Xn_curr = Xn_prev - (f0(Xn_prev) / (f0(segment.a) - f0(Xn_prev))) * (segment.a - Xn_prev);
            while (fabs(Xn_curr - Xn_prev) > eps && iterations < MAX_ITERATIONS) {
                Xn_prev = Xn_curr;
                Xn_curr = Xn_prev - (f0(Xn_prev) / (f0(segment.a) - f0(Xn_prev))) * (segment.a - Xn_prev);

                ++iterations;
            }
        }
        return Result(Xn_curr, iterations);
    }

    Result Newthon_method(Segment segment, double eps) { //метод Ньютона

        if (number_of_roots(segment) != 1)	// только 1 корень на промежутке
            return Result(-1, -1);

        int iterations = 1;

        double Xn_prev = 0;
        if (f0(segment.b) >= 0)
            Xn_prev = segment.b;
        else
            Xn_prev = segment.a;

        double Xn_curr = Xn_prev - f0(Xn_prev) / f1(Xn_prev);

        while (fabs(Xn_curr - Xn_prev) > eps && iterations < MAX_ITERATIONS) {
            Xn_prev = Xn_curr;
            Xn_curr = Xn_prev - f0(Xn_prev) / f1(Xn_prev);

            ++iterations;
        }
        return Result(Xn_curr, iterations);
    }
};

int main() {

    cout.setf(ios_base::fixed);

    double leftSegment = -10; //левый
    double rightSegment = 10; //правый

    //коэффициенты
    double a = 9.57496;
    double b = -243.672;
    double c = 773.65;
    // double a = 14.3455;
    // double b = 0;
    // double c = 0;
    Polynomial polynomial(a, b, c);
    //eps
    double eps = 0.0001;
    //Количество знаков после запятой
    int signs = 4;
    //Отделять корни табличным методом с шагом
    double step = 1;

    cout << "Промежуток: [" << setprecision(signs) << leftSegment << ", "		//Вывод отрезка
         << setprecision(signs) << rightSegment << "]\n";

    int rootsNumber = polynomial.number_of_roots(Segment(leftSegment, rightSegment));
    cout << "Количество корней: " << rootsNumber << "\n\n";								//Кол-во корней

    vector<Segment> segmentsWithRoots = polynomial.segment_with_roots(Segment(leftSegment, rightSegment), step);

    if (rootsNumber != segmentsWithRoots.size()) {							//Если обнаружен корень чётной кратности, то нужно отделить корни вручную
        cout << "**********************************************************\nОбнаружен корень чётной кратности. \n";
        cout << "Нужно отделить корни вручную. \n\n";

        segmentsWithRoots.clear();
        segmentsWithRoots.resize(rootsNumber);

        for (int i = 0; i < rootsNumber; i++) {
            cout << "Промежуток с корнем " << i + 1 << ": \n";			//Отрезок с корнем
            cin >> segmentsWithRoots[i].a >> segmentsWithRoots[i].b;
        }
    }
    else {
        cout << "Промежутки: \n";												//Отрезки
        for (const auto segment : segmentsWithRoots)
            cout << "[" << setprecision(signs) << segment.a << ", " << segment.b << "]\n";
    }

    map<int, string> methodsNames({ make_pair(0, "Метод половинного деления: "),
                                    make_pair(1, "Метод хорд: "),
                                    make_pair(2, "Метод Ньютона: ") });

    map<string, vector<Result> > results;
    for (int i = 0; i < rootsNumber; i++) {
        results["Метод половинного деления: "].push_back(polynomial.half_division(segmentsWithRoots[i], eps));
        results["Метод хорд: "].push_back(polynomial.chord_method(segmentsWithRoots[i], eps));
        results["Метод Ньютона: "].push_back(polynomial.Newthon_method(segmentsWithRoots[i], eps));
    }

    for (int i = 0; i < rootsNumber; i++) {

        cout << "\nПромежуток [" << setprecision(signs) << segmentsWithRoots[i].a
             << ", " << setprecision(signs) << segmentsWithRoots[i].b << "]: \n";

        for (int j = 0; j < 3; j++) {
            cout << setw(27) << right << methodsNames[j];

            if (results[methodsNames[j]][i].iterations == -1)
                cout << "Решение этим методом невозможно для этого промежутка \n";
            else
                cout << setw(signs + 3) << right << setprecision(signs) << results[methodsNames[j]][i].rootOfEq
                     << ". Число итерации: " << results[methodsNames[j]][i].iterations << "\n";	  // Кол-во итераций
        }
    }
}


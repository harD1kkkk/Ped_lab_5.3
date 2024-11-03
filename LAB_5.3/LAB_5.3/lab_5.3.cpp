#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double z(const double x);
int factorial(const int n);


int main() {
    double p_start, p_end;
    int n;

    cout << "p_start = "; cin >> p_start;
    cout << "p_end = "; cin >> p_end;
    cout << "n = "; cin >> n;

    double dp = (p_end - p_start) / n;
    double p = p_start;

    cout << fixed;
    cout << "-----------------------------------------" << endl;
    cout << "|    p    |         z(p)                |" << endl;
    cout << "-----------------------------------------" << endl;

    while (p <= p_end) {
        double result = z(p * p) + 2 * z(2 * p + p * p) + 1;
        cout << "| " << setw(7) << setprecision(2) << p << " | "
            << setw(24) << setprecision(10) << result << "    |" << endl;

        p += dp;
    }

    cout << "-----------------------------------------" << endl;

    return 0;
}
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}
double z(const double x) {
    if (abs(x) >= 1) {
        return (cos(2 * x) + 1) / (cos(x) + sin(x) * sin(x));
    }
    else {
        double S = 0;   
        double term = 1; 
        int k = 0;

        do {
            if (k > 0) {
                double R = (pow(2, 2 * k + 1) * pow(x, 2 * k + 1)) / factorial(2 * k + 1);
                term *= R; 
            }
            S += term; 
            k++;
        } while (k <= 6);

        return S;
    }
}
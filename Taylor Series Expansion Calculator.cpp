#include <iostream>
#include <cmath>

double factorial(int n) {
    if (n == 0)
        return 1;
    double fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

double taylorSeries(double x, int n) {
    double sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum += pow(x, i) / factorial(i);
    }
    return sum;
}

int main() {
    double x;
    int n;

    std::cout << "Enter the value of x: ";
    std::cin >> x;
    std::cout << "Enter the number of terms in the series (n): ";
    std::cin >> n;

    double result = taylorSeries(x, n);

    std::cout << "Result of Taylor series expansion: " << result << std::endl;

    return 0;
}

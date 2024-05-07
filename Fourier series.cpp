#include <iostream>
#include <cmath>
#include <vector>

// Define the function for which Fourier series is to be calculated
double function(double x) {
    return x * x; // Example function: f(x) = x^2
}

// Calculate Fourier series coefficients
std::vector<double> fourierCoefficients(double(*f)(double), double a, double b, int n) {
    std::vector<double> coefficients;
    double dx = (b - a) / n;

    for (int k = 0; k <= n; ++k) {
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            double x = a + i * dx;
            sum += f(x) * cos(2 * M_PI * k * x / (b - a));
        }
        sum *= 2.0 / (b - a);
        coefficients.push_back(sum);
    }

    return coefficients;
}

// Calculate Fourier series approximation
double fourierSeries(double(*f)(double), double a, double b, int n, double x) {
    double sum = 0;
    for (int k = 0; k <= n; ++k) {
        sum += fourierCoefficients(f, a, b, n)[k] * cos(2 * M_PI * k * x / (b - a));
    }
    return sum;
}

int main() {
    double a, b; // Range [a, b]
    int n; // Number of terms in the Fourier series

    // Input range and number of terms
    std::cout << "Enter the range [a, b]: ";
    std::cin >> a >> b;
    std::cout << "Enter the number of terms in the Fourier series: ";
    std::cin >> n;

    // Calculate and display Fourier series coefficients
    std::vector<double> coeffs = fourierCoefficients(function, a, b, n);
    std::cout << "Fourier series coefficients: ";
    for (int k = 0; k <= n; ++k) {
        std::cout << coeffs[k] << " ";
    }
    std::cout << std::endl;

    // Input value of x for Fourier series approximation
    double x;
    std::cout << "Enter the value of x for Fourier series approximation: ";
    std::cin >> x;

    // Calculate and display Fourier series approximation at x
    double result = fourierSeries(function, a, b, n, x);
    std::cout << "Fourier series approximation at x = " << x << ": " << result << std::endl;

    return 0;
}

#include <iostream>
#include <functional>
#include <complex>
#include <cmath>

// Function to compute Laplace transform using numerical integration (Trapezoidal rule)
std::complex<double> laplaceTransform(std::function<std::complex<double>(double)> f, double s, double a, double b, int n) {
    double h = (b - a) / n;
    std::complex<double> sum = 0.5 * (f(a) * exp(-s * a) + f(b) * exp(-s * b)); // Sum of function values at end points

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += f(x) * exp(-s * x); // Sum of function values at interior points
    }

    return h * sum;
}

int main() {
    double s; // Laplace variable 's'
    double a, b; // Integration limits [a, b]
    int n; // Number of intervals

    // Input Laplace variable and integration limits
    std::cout << "Enter the Laplace variable 's': ";
    std::cin >> s;
    std::cout << "Enter the lower limit of integration: ";
    std::cin >> a;
    std::cout << "Enter the upper limit of integration: ";
    std::cin >> b;
    std::cout << "Enter the number of intervals: ";
    std::cin >> n;

    // Define the function for which Laplace transform is to be computed (e.g., f(x) = exp(-x))
    auto f = [](double x) { return std::exp(-x); };

    // Compute and display the Laplace transform
    std::complex<double> result = laplaceTransform(f, s, a, b, n);
    std::cout << "Laplace transform: " << result.real() << " + " << result.imag() << "i" << std::endl;

    return 0;
}

#include <iostream>
#include <functional>

// Trapezoidal rule for numerical integration
double trapezoidalRule(std::function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b)); // Sum of function values at end points

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += f(x); // Sum of function values at interior points
    }

    return h * sum;
}

int main() {
    double a, b; // Integration limits [a, b]
    int n; // Number of intervals

    // Input integration limits and number of intervals
    std::cout << "Enter the lower limit of integration: ";
    std::cin >> a;
    std::cout << "Enter the upper limit of integration: ";
    std::cin >> b;
    std::cout << "Enter the number of intervals: ";
    std::cin >> n;

    // Define the function to be integrated (e.g., f(x) = x^2)
    auto f = [](double x) { return x * x; };

    // Calculate and display the result of numerical integration
    double result = trapezoidalRule(f, a, b, n);
    std::cout << "Result of numerical integration using trapezoidal rule: " << result << std::endl;

    return 0;
}

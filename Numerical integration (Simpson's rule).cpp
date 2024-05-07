 #include <iostream>
#include <functional>

// Function to be integrated
double function(double x) {
    return x * x; // Example function: f(x) = x^2
}

// Simpson's rule for numerical integration
double simpsonsRule(std::function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i += 2) {
        sum += 4 * f(a + i * h);
    }

    for (int i = 2; i < n - 1; i += 2) {
        sum += 2 * f(a + i * h);
    }

    return sum * h / 3.0;
}

int main() {
    double a, b; // Integration interval [a, b]
    int n; // Number of subintervals

    // Input integration interval and number of subintervals
    std::cout << "Enter the lower limit of integration (a): ";
    std::cin >> a;
    std::cout << "Enter the upper limit of integration (b): ";
    std::cin >> b;
    std::cout << "Enter the number of subintervals (n): ";
    std::cin >> n;

    // Calculate and display the integral approximation using Simpson's rule
    double result = simpsonsRule(function, a, b, n);
    std::cout << "Integral approximation using Simpson's rule: " << result << std::endl;

    return 0;
}

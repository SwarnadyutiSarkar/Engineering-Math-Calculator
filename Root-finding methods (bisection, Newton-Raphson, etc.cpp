#include <iostream>
#include <cmath>

// Function for which root is to be found
double function(double x) {
    return x * x - 4; // Example function: f(x) = x^2 - 4
}

// Bisection method
double bisection(double a, double b, double tol) {
    double c;
    while ((b - a) >= tol) {
        c = (a + b) / 2;
        if (function(c) == 0.0) {
            return c;
        } else if (function(c) * function(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}

// Derivative of the function
double derivative(double x) {
    return 2 * x; // Derivative of f(x) = x^2 - 4
}

// Newton-Raphson method
double newtonRaphson(double x0, double tol) {
    double x = x0;
    while (std::abs(function(x)) >= tol) {
        x = x - function(x) / derivative(x);
    }
    return x;
}

int main() {
    double a, b, tol, x0;

    // Input values
    std::cout << "Enter the range [a, b] for bisection method: ";
    std::cin >> a >> b;
    std::cout << "Enter the tolerance for both methods: ";
    std::cin >> tol;
    std::cout << "Enter the initial guess for Newton-Raphson method: ";
    std::cin >> x0;

    // Bisection method
    double root_bisection = bisection(a, b, tol);
    std::cout << "Root using bisection method: " << root_bisection << std::endl;

    // Newton-Raphson method
    double root_newton_raphson = newtonRaphson(x0, tol);
    std::cout << "Root using Newton-Raphson method: " << root_newton_raphson << std::endl;

    return 0;
}

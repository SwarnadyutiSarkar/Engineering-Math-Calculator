#include <iostream>
#include <cmath>

// Define the ordinary differential equation (ODE)
double ODE(double x, double y) {
    return x + y; // Example: dy/dx = x + y
}

// Runge-Kutta 4th Order Method to solve the ODE
double rungeKutta(double x0, double y0, double x, double h) {
    int n = (int)((x - x0) / h);
    double k1, k2, k3, k4, yn;
    yn = y0;
    for (int i = 1; i <= n; i++) {
        k1 = h * ODE(x0, yn);
        k2 = h * ODE(x0 + 0.5 * h, yn + 0.5 * k1);
        k3 = h * ODE(x0 + 0.5 * h, yn + 0.5 * k2);
        k4 = h * ODE(x0 + h, yn + k3);

        // Update y using the weighted average of four slopes
        yn = yn + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);

        // Update x
        x0 = x0 + h;
    }
    return yn;
}

int main() {
    double x0, y0, x, h;

    // Input initial values
    std::cout << "Enter initial value of x: ";
    std::cin >> x0;
    std::cout << "Enter initial value of y: ";
    std::cin >> y0;

    // Input final value of x
    std::cout << "Enter the value of x at which you want to find y: ";
    std::cin >> x;

    // Input step size
    std::cout << "Enter the step size (h): ";
    std::cin >> h;

    // Calculate and display the solution
    double result = rungeKutta(x0, y0, x, h);
    std::cout << "Approximate solution at x = " << x << ": y = " << result << std::endl;

    return 0;
}

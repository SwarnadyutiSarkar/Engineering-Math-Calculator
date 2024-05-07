#include <iostream>
#include <vector>
#include <cmath>

// Function to perform linear interpolation
double linearInterpolation(double x0, double x1, double y0, double y1, double x) {
    return y0 + (y1 - y0) / (x1 - x0) * (x - x0);
}

// Function to perform polynomial interpolation using Lagrange's method
double lagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double x_input) {
    double result = 0;
    for (size_t i = 0; i < x.size(); ++i) {
        double term = y[i];
        for (size_t j = 0; j < x.size(); ++j) {
            if (j != i) {
                term *= (x_input - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

// Function to perform polynomial curve fitting using the least squares method
std::vector<double> leastSquaresCurveFitting(const std::vector<double>& x, const std::vector<double>& y, int degree) {
    std::vector<double> coefficients(degree + 1, 0);
    int n = x.size();

    // Create the Vandermonde matrix
    std::vector<std::vector<double>> vandermonde(n, std::vector<double>(degree + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= degree; ++j) {
            vandermonde[i][j] = pow(x[i], j);
        }
    }

    // Solve the normal equations to get the coefficients
    for (int i = 0; i <= degree; ++i) {
        for (int j = 0; j <= degree; ++j) {
            for (int k = 0; k < n; ++k) {
                coefficients[i] += vandermonde[k][i] * vandermonde[k][j];
            }
        }
    }

    return coefficients;
}

int main() {
    // Input data points
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {2, 3, 5, 4, 6};

    // Input value for interpolation or curve fitting
    double x_input;
    std::cout << "Enter the value of x for interpolation or curve fitting: ";
    std::cin >> x_input;

    // Linear interpolation
    double linearInterpolatedValue = linearInterpolation(x[0], x[1], y[0], y[1], x_input);
    std::cout << "Linear interpolated value at x = " << x_input << ": " << linearInterpolatedValue << std::endl;

    // Polynomial interpolation (Lagrange's method)
    double lagrangeInterpolatedValue = lagrangeInterpolation(x, y, x_input);
    std::cout << "Polynomial interpolated value at x = " << x_input << ": " << lagrangeInterpolatedValue << std::endl;

    // Polynomial curve fitting (least squares method)
    int degree;
    std::cout << "Enter the degree of polynomial for curve fitting: ";
    std::cin >> degree;
    std::vector<double> coefficients = leastSquaresCurveFitting(x, y, degree);
    double curveFittedValue = 0;
    for (int i = 0; i <= degree; ++i) {
        curveFittedValue += coefficients[i] * pow(x_input, i);
    }
    std::cout << "Curve fitted value at x = " << x_input << ": " << curveFittedValue << std::endl;

    return 0;
}

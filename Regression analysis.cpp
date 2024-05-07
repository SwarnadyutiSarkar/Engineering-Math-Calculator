#include <iostream>
#include <vector>
#include <cmath>

// Function to perform linear regression
void linearRegression(const std::vector<double>& x, const std::vector<double>& y, double& slope, double& intercept) {
    int n = x.size();

    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_squared = 0;
    for (int i = 0; i < n; ++i) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x_squared += x[i] * x[i];
    }

    double x_mean = sum_x / n;
    double y_mean = sum_y / n;

    slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x * sum_x);
    intercept = y_mean - slope * x_mean;
}

int main() {
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {2, 3, 4, 5, 6};

    double slope, intercept;
    linearRegression(x, y, slope, intercept);

    std::cout << "Linear Regression Equation: y = " << slope << "x + " << intercept << std::endl;

    return 0;
}

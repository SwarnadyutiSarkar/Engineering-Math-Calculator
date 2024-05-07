#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> calculatePolynomialRoots(const vector<double>& coefficients) {
    int degree = coefficients.size() - 1;
    vector<double> roots;

    if (degree == 1) { // Linear equation
        double root = -coefficients[0] / coefficients[1];
        roots.push_back(root);
    } else if (degree == 2) { // Quadratic equation
        double a = coefficients[2];
        double b = coefficients[1];
        double c = coefficients[0];
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            roots.push_back(root1);
            roots.push_back(root2);
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            roots.push_back(root);
        }
    } // Add more conditions for higher-degree polynomials if needed

    return roots;
}

int main() {
    vector<double> coefficients;
    int degree;

    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    cout << "Enter the coefficients in descending order of degree:" << endl;
    for (int i = degree; i >= 0; --i) {
        double coeff;
        cout << "Coefficient of x^" << i << ": ";
        cin >> coeff;
        coefficients.push_back(coeff);
    }

    vector<double> roots = calculatePolynomialRoots(coefficients);

    cout << "Roots:" << endl;
    for (double root : roots) {
        cout << root << endl;
    }

    return 0;
}

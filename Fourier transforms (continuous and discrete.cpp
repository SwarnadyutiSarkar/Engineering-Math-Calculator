#include <iostream>
#include <cmath>
#include <vector>
#include <complex>

// Function to calculate continuous Fourier transform
std::vector<std::complex<double>> continuousFourierTransform(const std::vector<double>& x, const std::vector<double>& y) {
    int N = x.size();
    std::vector<std::complex<double>> result;

    for (int k = 0; k < N; ++k) {
        std::complex<double> sum(0.0, 0.0);
        for (int n = 0; n < N; ++n) {
            sum += y[n] * std::exp(-2.0 * M_PI * std::complex<double>(0.0, 1.0) * k * x[n] / (double)N);
        }
        result.push_back(sum / (double)N);
    }

    return result;
}

// Function to calculate discrete Fourier transform
std::vector<std::complex<double>> discreteFourierTransform(const std::vector<double>& x, const std::vector<double>& y) {
    int N = x.size();
    std::vector<std::complex<double>> result;

    for (int k = 0; k < N; ++k) {
        std::complex<double> sum(0.0, 0.0);
        for (int n = 0; n < N; ++n) {
            sum += y[n] * std::exp(-2.0 * M_PI * std::complex<double>(0.0, 1.0) * k * n / (double)N);
        }
        result.push_back(sum);
    }

    return result;
}

// Function to display complex vector
void displayComplexVector(const std::vector<std::complex<double>>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "Element " << i << ": " << vec[i] << std::endl;
    }
}

int main() {
    // User input data
    std::vector<double> x = {0.0, 1.0, 2.0, 3.0, 4.0};
    std::vector<double> y = {1.0, 2.0, 3.0, 2.0, 1.0};

    // Calculate and display continuous Fourier transform
    std::cout << "Continuous Fourier Transform:\n";
    std::vector<std::complex<double>> continuousFT = continuousFourierTransform(x, y);
    displayComplexVector(continuousFT);

    // Calculate and display discrete Fourier transform
    std::cout << "\nDiscrete Fourier Transform:\n";
    std::vector<std::complex<double>> discreteFT = discreteFourierTransform(x, y);
    displayComplexVector(discreteFT);

    return 0;
}

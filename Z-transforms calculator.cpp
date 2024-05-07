#include <iostream>
#include <complex>
#include <vector>

// Calculate the Z-transform of a discrete-time signal
std::vector<std::complex<double>> zTransform(const std::vector<double>& x) {
    int N = x.size();
    std::vector<std::complex<double>> X(N);

    for (int k = 0; k < N; ++k) {
        std::complex<double> sum = 0;
        for (int n = 0; n < N; ++n) {
            sum += x[n] * std::polar(1.0, -2.0 * M_PI * k * n / N);
        }
        X[k] = sum;
    }

    return X;
}

int main() {
    int N; // Number of samples
    std::cout << "Enter the number of samples: ";
    std::cin >> N;

    std::vector<double> x(N);
    std::cout << "Enter the discrete-time signal samples:\n";
    for (int i = 0; i < N; ++i) {
        std::cin >> x[i];
    }

    // Calculate the Z-transform
    std::vector<std::complex<double>> X = zTransform(x);

    // Display the Z-transform
    std::cout << "Z-transform of the signal:\n";
    for (int k = 0; k < N; ++k) {
        std::cout << "X(" << k << ") = " << X[k] << std::endl;
    }

    return 0;
}

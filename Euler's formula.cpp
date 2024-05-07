#include <iostream>
#include <cmath>
#include <complex>

int main() {
    double x;
    std::cout << "Enter the value of x: ";
    std::cin >> x;

    std::complex<double> result = exp(std::complex<double>(0, x));

    std::cout << "e^(i*" << x << ") = " << result << std::endl;

    return 0;
}

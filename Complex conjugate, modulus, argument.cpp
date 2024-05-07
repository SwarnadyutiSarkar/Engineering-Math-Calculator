#include <iostream>
#include <cmath>
#include <complex>

int main() {
    double real, imag;

    // Input the real and imaginary parts of the complex number
    std::cout << "Enter the real part of the complex number: ";
    std::cin >> real;
    std::cout << "Enter the imaginary part of the complex number: ";
    std::cin >> imag;

    // Create a complex number object
    std::complex<double> z(real, imag);

    // Calculate and output the complex conjugate
    std::complex<double> conjugate = std::conj(z);
    std::cout << "Complex Conjugate: " << conjugate.real() << " + " << conjugate.imag() << "i" << std::endl;

    // Calculate and output the modulus
    double modulus = std::abs(z);
    std::cout << "Modulus: " << modulus << std::endl;

    // Calculate and output the argument (in radians)
    double argument = std::arg(z);
    std::cout << "Argument (in radians): " << argument << std::endl;

    return 0;
}

#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) const {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    Complex operator/(const Complex& c) const {
        double denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator,
                       (imag * c.real - real * c.imag) / denominator);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}

int main() {
    double real1, imag1, real2, imag2;

    std::cout << "Enter real and imaginary parts of first complex number: ";
    std::cin >> real1 >> imag1;

    std::cout << "Enter real and imaginary parts of second complex number: ";
    std::cin >> real2 >> imag2;

    Complex num1(real1, imag1);
    Complex num2(real2, imag2);

    Complex sum = num1 + num2;
    Complex diff = num1 - num2;
    Complex prod = num1 * num2;
    Complex quot = num1 / num2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;
    std::cout << "Product: " << prod << std::endl;
    std::cout << "Quotient: " << quot << std::endl;

    return 0;
}

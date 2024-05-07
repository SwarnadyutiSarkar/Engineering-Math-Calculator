#include <iostream>
#include <cmath>

// Function to calculate factorial
double factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    double fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// Function to calculate binomial coefficient
double binomialCoeff(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to calculate binomial probability
double binomialProbability(int n, int k, double p) {
    return binomialCoeff(n, k) * pow(p, k) * pow(1 - p, n - k);
}

// Function to calculate Poisson probability
double poissonProbability(int k, double lambda) {
    return exp(-lambda) * pow(lambda, k) / factorial(k);
}

// Function to calculate normal probability density function
double normalPDF(double x, double mean, double stddev) {
    return exp(-0.5 * pow((x - mean) / stddev, 2)) / (stddev * sqrt(2 * M_PI));
}

// Function to calculate cumulative normal distribution function
double cumulativeNormalCDF(double x, double mean, double stddev) {
    return 0.5 * (1 + erf((x - mean) / (stddev * sqrt(2))));
}

int main() {
    int choice;
    std::cout << "Select a probability distribution:\n";
    std::cout << "1. Binomial\n";
    std::cout << "2. Poisson\n";
    std::cout << "3. Normal\n";
    std::cin >> choice;

    if (choice == 1) { // Binomial distribution
        int n, k;
        double p;
        std::cout << "Enter the number of trials (n): ";
        std::cin >> n;
        std::cout << "Enter the number of successes (k): ";
        std::cin >> k;
        std::cout << "Enter the probability of success (p): ";
        std::cin >> p;
        std::cout << "Binomial Probability: " << binomialProbability(n, k, p) << std::endl;
    } else if (choice == 2) { // Poisson distribution
        int k;
        double lambda;
        std::cout << "Enter the number of events (k): ";
        std::cin >> k;
        std::cout << "Enter the mean rate (lambda): ";
        std::cin >> lambda;
        std::cout << "Poisson Probability: " << poissonProbability(k, lambda) << std::endl;
    } else if (choice == 3) { // Normal distribution
        double x, mean, stddev;
        std::cout << "Enter the value of x: ";
        std::cin >> x;
        std::cout << "Enter the mean: ";
        std::cin >> mean;
        std::cout << "Enter the standard deviation: ";
        std::cin >> stddev;
        std::cout << "Normal Probability Density: " << normalPDF(x, mean, stddev) << std::endl;
        std::cout << "Cumulative Normal Distribution: " << cumulativeNormalCDF(x, mean, stddev) << std::endl;
    } else {
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}

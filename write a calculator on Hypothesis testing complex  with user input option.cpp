#include <iostream>
#include <cmath>
#include <iomanip>

// Function to perform one-sample z-test
std::string oneSampleZTest(double sampleMean, double populationMean, double populationStdDev, int sampleSize, double alpha) {
    double zScore = (sampleMean - populationMean) / (populationStdDev / sqrt(sampleSize));
    double pValue = 0.5 * (1 + erf(zScore / sqrt(2))); // Using cumulative distribution function (CDF) of standard normal distribution

    if (pValue < alpha) {
        return "Reject null hypothesis: There is sufficient evidence to say that the population mean is different from the sample mean.";
    } else {
        return "Fail to reject null hypothesis: There is not enough evidence to conclude that the population mean is different from the sample mean.";
    }
}

int main() {
    double sampleMean, populationMean, populationStdDev, alpha;
    int sampleSize;

    // Input sample statistics and parameters
    std::cout << "Enter the sample mean: ";
    std::cin >> sampleMean;
    std::cout << "Enter the population mean: ";
    std::cin >> populationMean;
    std::cout << "Enter the population standard deviation: ";
    std::cin >> populationStdDev;
    std::cout << "Enter the sample size: ";
    std::cin >> sampleSize;
    std::cout << "Enter the significance level (alpha): ";
    std::cin >> alpha;

    // Perform one-sample z-test
    std::string result = oneSampleZTest(sampleMean, populationMean, populationStdDev, sampleSize, alpha);

    // Output result
    std::cout << std::endl << result << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <fftw3.h>

// Function to perform Fast Fourier Transform (FFT)
std::vector<std::complex<double>> fft(const std::vector<double>& signal) {
    int n = signal.size();

    // Allocate input and output arrays for FFT
    double* in = (double*) fftw_malloc(sizeof(double) * n);
    fftw_complex* out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * n);

    // Create FFT plan
    fftw_plan plan = fftw_plan_dft_r2c_1d(n, in, out, FFTW_ESTIMATE);

    // Copy signal data to input array
    for (int i = 0; i < n; ++i) {
        in[i] = signal[i];
    }

    // Perform FFT
    fftw_execute(plan);

    // Copy FFT result to a vector of complex numbers
    std::vector<std::complex<double>> result;
    for (int i = 0; i < n; ++i) {
        result.push_back(std::complex<double>(out[i][0], out[i][1]));
    }

    // Free allocated memory and destroy FFT plan
    fftw_destroy_plan(plan);
    fftw_free(in);
    fftw_free(out);

    return result;
}

int main() {
    // Input signal
    std::vector<double> signal = {1, 2, 3, 4, 5, 6, 7, 8};

    // Perform FFT
    std::vector<std::complex<double>> spectrum = fft(signal);

    // Output frequency spectrum
    std::cout << "Frequency Spectrum:\n";
    for (int i = 0; i < spectrum.size(); ++i) {
        std::cout << "Frequency " << i << ": " << spectrum[i] << std::endl;
    }

    return 0;
}

#include <iostream>
#include <vector>

// Function to solve the 1D heat equation using the finite difference method
void solveHeatEquation(std::vector<double>& u, double alpha, double dt, int num_steps) {
    int n = u.size();
    std::vector<double> next_u(n);

    for (int step = 0; step < num_steps; ++step) {
        // Apply finite difference scheme
        for (int i = 1; i < n - 1; ++i) {
            next_u[i] = u[i] + alpha * (u[i - 1] - 2 * u[i] + u[i + 1]);
        }

        // Update u for the next time step
        u = next_u;
    }
}

int main() {
    // Define parameters
    double alpha = 0.1; // Thermal diffusivity
    double dt = 0.01;   // Time step
    int num_steps = 100; // Number of time steps
    int n = 11;          // Number of grid points (including boundary points)
    
    // Initial condition
    std::vector<double> u(n, 0.0);
    u[n/2] = 1.0; // Initial temperature spike at the center

    // Solve the heat equation
    solveHeatEquation(u, alpha, dt, num_steps);

    // Output the final temperature distribution
    std::cout << "Final temperature distribution:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "u[" << i << "] = " << u[i] << std::endl;
    }

    return 0;
}

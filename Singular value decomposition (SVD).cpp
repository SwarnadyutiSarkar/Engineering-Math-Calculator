#include <iostream>
#include <Eigen/Dense>

int main() {
    // Input matrix dimensions
    int rows, cols;
    std::cout << "Enter the number of rows in the matrix: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns in the matrix: ";
    std::cin >> cols;

    // Input matrix elements
    Eigen::MatrixXd matrix(rows, cols);
    std::cout << "Enter the elements of the matrix row-wise:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix(i, j);
        }
    }

    // Perform SVD
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(matrix, Eigen::ComputeThinU | Eigen::ComputeThinV);

    // Output singular values
    std::cout << "Singular values:\n" << svd.singularValues() << std::endl;

    // Output left singular vectors
    std::cout << "Left singular vectors:\n" << svd.matrixU() << std::endl;

    // Output right singular vectors
    std::cout << "Right singular vectors:\n" << svd.matrixV() << std::endl;

    return 0;
}

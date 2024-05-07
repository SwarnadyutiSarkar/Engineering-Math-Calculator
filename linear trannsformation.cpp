#include <iostream>
#include <vector>

// Function to perform matrix multiplication
std::vector<std::vector<int>> matrixMultiplication(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int m = A.size();
    int n = B[0].size();
    int p = B.size();

    std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < p; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Function to perform scalar multiplication of a matrix
std::vector<std::vector<int>> scalarMultiplication(int scalar, const std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = scalar * matrix[i][j];
        }
    }

    return result;
}

// Function to print a matrix
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int m, n;
    std::cout << "Enter the number of rows and columns of the matrix: ";
    std::cin >> m >> n;

    std::cout << "Enter the elements of the matrix:" << std::endl;
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Matrix:" << std::endl;
    printMatrix(matrix);

    int scalar;
    std::cout << "Enter a scalar value: ";
    std::cin >> scalar;

    std::cout << "Result of scalar multiplication:" << std::endl;
    printMatrix(scalarMultiplication(scalar, matrix));

    std::vector<std::vector<int>> anotherMatrix(m, std::vector<int>(n));
    std::cout << "Enter another matrix for addition:" << std::endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> anotherMatrix[i][j];
        }
    }

    std::cout << "Result of addition:" << std::endl;
    printMatrix(matrixMultiplication(matrix, anotherMatrix));

    return 0;
}

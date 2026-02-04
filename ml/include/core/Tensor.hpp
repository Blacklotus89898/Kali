#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <vector>
#include <iostream>
#include <cassert>
#include <random>

namespace ml {

class Matrix {
public:
    int rows, cols;
    std::vector<double> data; // Contiguous storage

    Matrix(int r, int c) : rows(r), cols(c), data(r * c, 0.0) {}

    // Access element at (r, c)
    double& operator()(int r, int c) {
        return data[r * cols + c];
    }

    const double& operator()(int r, int c) const {
        return data[r * cols + c];
    }

    // Matrix Multiplication: C = A * B
    // Dimensions: (m x n) * (n x p) -> (m x p)
    static Matrix multiply(const Matrix& A, const Matrix& B) {
        assert(A.cols == B.rows && "Dimension mismatch for multiplication");
        Matrix C(A.rows, B.cols);

        for (int i = 0; i < A.rows; ++i) {
            for (int k = 0; k < A.cols; ++k) { // K-loop inside for cache efficiency
                double temp = A(i, k);
                for (int j = 0; j < B.cols; ++j) {
                    C(i, j) += temp * B(k, j);
                }
            }
        }
        return C;
    }

    // Transpose: A^T
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(j, i) = (*this)(i, j);
            }
        }
        return result;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << (*this)(i, j) << " ";
            }
            std::cout << "\n";
        }
    }

    // Inside class Matrix in Tensor.hpp
void fill(double value) {
    for (auto& val : data) {
        val = value;
    }
}
};

} // namespace ml

#endif

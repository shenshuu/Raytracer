#include "utilities.h"
#include "matrix.h"
#include <iostream>
#include <stdexcept>

Matrix::Matrix() {
    rows_ = 3;
    cols_ = 3;
    matrix_ = std::vector<std::vector<double> >(rows_, std::vector<double>(cols_, 0.0));
}

Matrix::Matrix(int rows, int cols) {
    rows_ = rows;
    cols_ = cols;
    matrix_ = std::vector<std::vector<double> >(rows_, std::vector<double>(cols_, 0.0));
}

Matrix::Matrix(std::vector<std::vector<double> >& matrix) {
    rows_ = matrix.size();
    cols_ = matrix[0].size();
    matrix_ = matrix;
}

int Matrix::number_of_rows() {
    return rows_;
}

int Matrix::number_of_cols() {
    return cols_;
}

const std::vector<std::vector<double> > Matrix::get_matrix() {
    return matrix_;
}

bool Matrix::operator==(Matrix& other) {
    if (other.number_of_cols() != cols_ || other.number_of_rows() != rows_)
        return false;
    
    std::vector<std::vector<double> > other_ = other.get_matrix();
    
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            if (!check_equal(other_[i][j], matrix_[i][j]))
                return false;
        }
    }

    return true;
}

bool Matrix::operator!=(Matrix& other) {
    return !(*this == other);
}

Matrix Matrix::operator*(Matrix& other) {
    if (cols_ != other.number_of_rows())
        throw std::logic_error("invalid matrix dimensions for multiplying");
    
    std::vector<std::vector<double> > result(rows_, std::vector<double>(other.number_of_cols(), 0));

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < other.number_of_cols(); j++) {
            for (int k = 0; k < other.number_of_rows(); k++) {
                result[i][j] += matrix_[i][k] * other.element_at(k, j);
            }
        }
    }

    return Matrix(result);
}

Matrix Matrix::transpose() {
    std::vector<std::vector<double> > elements(cols_, std::vector<double>(rows_, 0));

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            elements[j][i] = matrix_[i][j];
        }
    }

    return Matrix(elements);
}

double Matrix::element_at(int row, int col) {
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_)
        throw std::out_of_range("row or col out of range");
    return matrix_[row][col];
}

double Matrix::determinant() {
    if (number_of_rows() == 2 && number_of_cols() == 2) 
        return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];

    double d = 0.0;
    for (int j = 0; j < cols_; j++) {
        d += matrix_[0][j] * cofactor(0,j);
    }

    return d;
}

double Matrix::minor(int row, int col) {
    return submatrix(row, col).determinant();
}

double Matrix::cofactor(int row, int col) {
    return minor(row, col) * ((row + col) % 2 ? -1 : 1);
}

Matrix Matrix::submatrix(int row, int col) {
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_)
        throw std::out_of_range("specified row or col must be within range of matrix");
    
    std::vector<std::vector<double> > result(rows_ - 1, std::vector<double>(cols_ - 1, 0));
    
    for (int i = 0; i < rows_; i++) {
        if (i == row) continue;
        for (int j = 0; j < cols_; j++) {
            if (j == col) continue;
            result[i >= row ? i-1 : i][j >= col ? j-1: j] = matrix_[i][j];
        }
    }

    return Matrix(result);
}

bool Matrix::invertable() {
    return determinant() != 0;
}

Matrix Matrix::scale(double c) {
    std::vector<std::vector<double> > result(rows_, std::vector<double>(cols_, 0));

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            result[i][j] = matrix_[i][j] * c;
        }
    }
    
    return Matrix(result);
}

Matrix Matrix::inverse() {
    if (!invertable())
        throw std::logic_error("cannot invert matrix with zero determinant");

    std::vector<std::vector<double> > cofactors(rows_, std::vector<double>(cols_, 0));
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            cofactors[i][j] = cofactor(i,j);
        }
    }
    
    Matrix m(cofactors);
    return m.transpose().scale(1.0 / determinant());
}

void Matrix::print() {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            std::cout << matrix_[i][j] << " ";
        }
        std::cout << "\n";
    }
}
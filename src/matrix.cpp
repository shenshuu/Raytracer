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
    
    std::vector<std::vector<double> > other_;
    
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            if (!check_equal(other_[i][j], matrix_[i][j]))
                return false;
        }
    }

    return true;
}

double Matrix::element_at(int row, int col) {
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_)
        throw std::out_of_range("row or col out of range");
    return matrix_[row][col];
}

void Matrix::print() {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            std::cout << matrix_[i][j] << " ";
        }
        std::cout << "\n";
    }
}
#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

class Matrix {
    public:
        // default constructor
        Matrix();

        // parameterized constructors
        Matrix(int rows, int cols);
        Matrix(std::vector<std::vector<double> >& matrix);

        // overloaded equality operator for testing
        bool operator==(Matrix& other);

        // overloaded inequality operator
        bool operator!=(Matrix& other);

        // overloaded multiplication operator
        Matrix operator*(Matrix& other);

        // transpose matrix
        Matrix transpose();

        // print function for debugging
        void print();

        // getter method for inspecting matrix
        const std::vector<std::vector<double> > get_matrix();

        // getter methods for number of rows/cols
        int number_of_rows();
        int number_of_cols();

        // returns element at specific position of matrix
        double element_at(int row, int col);

        // returns determinant of matrix
        double determinant();

        // returns minor of a matrix
        double minor(int row, int col);

        // returns cofactor of a matrix
        double cofactor(int row, int col);

        // removes specific row and column of matrix
        Matrix submatrix(int row, int col);

        // returns whether or not the matrix is invertable
        bool invertable();

        // inverts a matrix
        Matrix inverse();

        // multiplies matrix by scalar constant
        Matrix scale(double c);

    private:
        std::vector<std::vector<double> > matrix_;
        int rows_;
        int cols_;
};

#endif
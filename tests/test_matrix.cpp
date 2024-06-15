#include "../src/matrix.h"
#include <iostream>
#include <cassert>
#include <vector>

void test_create_matrix() {
    std::vector<std::vector<double> > elements = {
        {1, 2, 3, 4},
        {5.5, 6.5, 7.5, 8.5},
        {9, 10, 11, 12},
        {13.5, 14.5, 15.5, 16.5}
    };

    Matrix matrix(elements);

    assert(matrix.element_at(0,0) == 1.0);
    assert(matrix.element_at(1,0) == 5.5);
    assert(matrix.element_at(1,2) == 7.5);
    assert(matrix.element_at(3,1) == 14.5);

    std::cout << "test_create_matrix passed." << std::endl;
}

void test_matrix_equality() {
    std::vector<std::vector<double> > a = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {1, 2, 3, 4}
    };

    std::vector<std::vector<double> > b = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {1, 2, 3, 4}
    };

    std::vector<std::vector<double> > c = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {5, 4, 3, 2},
        {1, 2, 3, 4}
    };

    Matrix A(a), B(b), C(c);

    assert(A == B);
    assert(B != C);

    std::cout << "test_matrix_equality passed." << std::endl;
}

void test_matrix_multiplication() {
    std::vector<std::vector<double> > a = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}
    };

    std::vector<std::vector<double> > b = {
        {-2, 1, 2, 3},
        {3, 2, 1, -1},
        {4, 3, 6, 5},
        {1, 2, 7, 8}
    };

    std::vector<std::vector<double> > c = {
        {20, 22, 50, 48},
        {44, 54, 114, 108},
        {40, 58, 110, 102},
        {16, 26, 46, 42}
    };

    Matrix A(a), B(b), C(c);

    assert(A * B == C);

    std::cout << "test_matrix_multiplication passed." << std::endl;
}

void test_matrix_identity() {
    std::vector<std::vector<double> > a = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}
    };

    std::vector<std::vector<double> > identity = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    Matrix A(a), I(identity);

    assert(A * I == A);

    std::cout << "test_matrix_identity passed." << std::endl;
}

void test_matrix_transpose() {
    std::vector<std::vector<double> > a = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6}
    };

    std::vector<std::vector<double> > b = {
        {1, 5, 9},
        {2, 6, 8},
        {3, 7, 7},
        {4, 8, 6}
    };

    std::vector<std::vector<double> > identity = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    Matrix A(a), B(b), I(identity);

    assert(A.transpose() == B);
    assert(I.transpose() == I);

    std::cout << "test_matrix_transpose passed." << std::endl;
}

void test_submatrix() {
    std::vector<std::vector<double> > a = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}
    };

    std::vector<std::vector<double> > b = {
        {1, 2, 4},
        {9, 8, 6},
        {5, 4, 2}
    };

    std::vector<std::vector<double> > c = {
        {1, 2, 4},
        {9, 8, 6},
        {5, 4, 2}
    };

    std::vector<std::vector<double> > d = {
        {1, 2},
        {9, 8}
    };

    Matrix A(a), B(b), C(c), D(d);

    assert(A.submatrix(1, 2) == B);
    assert(C.submatrix(2, 2) == D);

    std::cout << "test_submatrix passed." << std::endl;
}

void test_matrix_minor() {
    std::vector<std::vector<double> > a = {
        {3, 5, 0},
        {2, -1, -7},
        {6, -1, 5}
    };

    Matrix A(a);

    assert(A.submatrix(1, 0).determinant() == 25);

    std::cout << "test_matrix_minor passed." << std::endl;
}

void test_matrix_cofactor() {
    std::vector<std::vector<double> > a = {
        {3, 5, 0},
        {2, -1, -7},
        {6, -1, 5}
    };

    Matrix A(a);

    assert(A.minor(0,0) == -12);
    assert(A.cofactor(0,0) == -12);
    assert(A.minor(1,0) == 25);
    assert(A.cofactor(1,0) == -25);

    std::cout << "test_matrix_cofactor passed." << std::endl;
}

void test_matrix_determinant() {
    std::vector<std::vector<double> > a = {
        {1, 2, 6},
        {-5, 8, -4},
        {2, 6, 4}
    };

    std::vector<std::vector<double> > b = {
        {-2, -8, 3, 5},
        {-3, 1, 7, 3},
        {1, 2, -9, 6},
        {-6, 7, 7, -9}
    };

    Matrix A(a), B(b);

    assert(A.cofactor(0,0) == 56);
    assert(A.cofactor(0,1) == 12);
    assert(A.cofactor(0,2) == -46);
    assert(A.determinant() == -196);

    assert(B.cofactor(0,0) == 690);
    assert(B.cofactor(0,1) == 447);
    assert(B.cofactor(0,2) == 210);
    assert(B.cofactor(0,3) == 51);
    assert(B.determinant() == -4071);

    std::cout << "test_matrix_determinant passed." << std::endl;
}
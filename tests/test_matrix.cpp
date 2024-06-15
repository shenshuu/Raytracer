#include "../src/utilities.h"
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

void test_matrix_invertability() {

    std::vector<std::vector<double> > a = {
        {6, 4, 4, 4},
        {5, 5, 7, 6},
        {4, -9, 3, -7},
        {9, 1, 7, -6}
    };

    std::vector<std::vector<double> > b = {
        {-4, 2, -2, -3},
        {9, 6, 2, 6},
        {0, -5, 1, -5},
        {0, 0, 0, 0}
    };

    Matrix A(a), B(b);

    assert(A.determinant() == -2120);
    assert(B.determinant() == 0);
    assert(A.invertable());
    assert(!B.invertable());

    std::cout << "test_matrix_invertability passed." << std::endl;
}

void test_matrix_inverse() {
    std::vector<std::vector<double> > a = {
        {-5, 2, 6, -8},
        {1, -5, 1, 8},
        {7, 7, -6, -7},
        {1, -3, 7, 4}
    };

    std::vector<std::vector<double> > b = {
        {8, -5, 9, 2},
        {7, 5, 6, 1},
        {-6, 0, 9, 6},
        {-3, 0, -9, -4}
    };

    std::vector<std::vector<double> > c = {
        {9, 3, 0, 9},
        {-5, -2, -6, -3},
        {-4, 9, 6, 4},
        {-7, 6, 6, 2}
    };

    std::vector<std::vector<double> > a_inverse = {
        {0.21805, 0.45113, 0.24060, -0.04511},
        {-0.80827, -1.45677, -0.44361, 0.52068},
        {-0.07895, -0.22368, -0.05263, 0.19737},
        {-0.52256, -0.81391, -0.30075, 0.30639}
    };

    std::vector<std::vector<double> > b_inverse = {
        {-0.15385, -0.15385, -0.28205, -0.53846},
        {-0.07692, 0.12308, 0.02564, 0.03077},
        {0.35897, 0.35897, 0.43590, 0.92380},
        {-0.69231, -0.69231, -0.76923, -1.92308}
    };

    std::vector<std::vector<double> > c_inverse = {
        {8, -5, 9, 2},
        {7, 5, 6, 1},
        {-6, 0, 9, 6},
        {-3, 0, -9, -4}
    };

    Matrix A(a), A_In(a_inverse);
    Matrix B(b), B_In(b_inverse);
    Matrix C(c), C_In(c_inverse);
    Matrix D = A * B;
    assert(A.determinant() == 532);
    assert(A.cofactor(2,3) == -160);
    assert(A.inverse().element_at(3,2) == -160.0 / 532.0);
    assert(A.cofactor(3,2) == 105);
    assert(A.inverse().element_at(2,3) == 105.0 / 532.0);

    assert(A.inverse() == A_In);
    Matrix B_In_true = B.inverse();
    assert(D * B_In_true == A);

    std::cout << "test_matrix_inverse passed." << std::endl;
}
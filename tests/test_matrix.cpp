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
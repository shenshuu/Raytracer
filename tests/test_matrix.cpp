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

    assert(a == b);
    assert(b != c);

    std::cout << "test_matrix_equality passed." << std::endl;
}
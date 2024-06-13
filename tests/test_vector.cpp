#include "../src/vector.h"
#include "../src/utilities.h"
#include <iostream>
#include <cassert>
#include <cmath>

void test_mag_vector() {
    Vector v1(0.0, 1.0, 0.0);
    Vector v2(1.0, 2.0, 3.0);
    Vector v3(0.0, 0.0, 1.0);

    assert(check_equal(v1.mag(), 1.0));
    assert(check_equal(v2.mag(), std::sqrt(14.0)));
    assert(check_equal(v3.mag(), 1.0));

    std::cout << "test_mag_vector passed." << std::endl;
}

void test_norm_vector() {
    Vector v1(4.0, 0.0, 0.0);
    Vector v2(1.0, 2.0, 3.0);

    double m = v2.mag();
    assert(v1.normalize() == Vector(1.0, 0.0, 0.0));
    assert(v2.normalize() == Vector(1.0 / m, 2.0 / m, 3.0 / m));

    std::cout << "test_norm_vector passed." << std::endl;
}

void test_dot_vector() {
    Vector v1(1.0, 2.0, 3.0);
    Vector v2(2.0, 3.0, 4.0);

    assert(check_equal(v1.dot(v2), 20.0));

    std::cout << "test_dot_vector passed." << std::endl;
}

void test_cross_vector() {
    Vector v1(1.0, 0.0, 0.0);
    Vector v2(0.0, 1.0, 0.0);
    Vector v3(1.0, 2.0, 3.0);
    Vector v4(2.0, 3.0, 4.0);

    assert(v1.cross(v2) == Vector(0.0, 0.0, 1.0));
    assert(v3.cross(v4) == Vector(-1.0, 2.0, -1.0));

    std::cout << "test_cross_vector passed." << std::endl;
}
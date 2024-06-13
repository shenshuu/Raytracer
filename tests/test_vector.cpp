#include "../src/vector.h"
#include "../src/utilities.h"
#include <cassert>
#include <iostream>
#include <math.h>

void test_mag_vector() {
    Vector v1(0.0, 1.0, 0.0);
    Vector v2(1.0, 2.0, 3.0);
    Vector v3(0.0, 0.0, 1.0);

    assert(check_equal(v1.mag(), 1.0));
    assert(check_equal(v2.mag(), std::sqrt(14.0)));
    assert(check_equal(v3.mag(), 1.0));

    // std::cout << "test_mag_vector passed" << std::endl;
}
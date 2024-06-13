#define EPSILON 1e-9
#include "utilities.h"
#include <cmath>

bool check_equal(double a, double b) {
    return std::abs(a - b) < EPSILON;
}
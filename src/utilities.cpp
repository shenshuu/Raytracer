#define EPSILON 1e-9
#include "utilities.h"
#include <math.h>

bool check_equal(double a, double b) {
    return std::fabs(a - b) < EPSILON;
}
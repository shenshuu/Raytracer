#define EPSILON 0.00001
#include <math.h>

bool check_equal(double a, double b) {
    return std::fabs(a - b) < EPSILON;
}
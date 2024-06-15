#define EPSILON 1e-5
#include "utilities.h"
#include <cmath>

int min_int(int a, int b) {
    return a > b ? b : a;
}

int max_int(int a, int b) {
    return a > b ? a : b;
}

double min_double(double a, double b) {
    return a > b ? b : a;
}

double max_double(double a, double b) {
    return a > b ? a : b;
}

bool check_equal(double a, double b) {
    return std::abs(a - b) < EPSILON;
}
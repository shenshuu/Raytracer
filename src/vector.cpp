#include "tuple.h"
#include "vector.h"
#include <math.h>

Vector::Vector() {
    Tuple(0, 0, 0, 0);
}

Vector::Vector(double x, double y, double z) {
    Tuple(x, y, z, 0);
}

double Vector::mag() {
    return std::sqrt(
        getX() * getX() +
        getY() * getY() +
        getZ() * getZ());
}
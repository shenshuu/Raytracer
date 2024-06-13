#include "tuple.h"
#include "vector.h"
#include <cmath>

Vector::Vector() : Tuple(0, 0, 0, 0) { }

Vector::Vector(double x, double y, double z) : Tuple(x, y, z, 0) { }

Vector Vector::normalize() {
    double m = mag();
    return Vector(getX() / m, getY() / m, getZ() / m);
}

double Vector::mag() {
    return std::sqrt(
        getX() * getX() +
        getY() * getY() +
        getZ() * getZ());
}

double Vector::dot(Vector& other) {
    return getX() * other.getX() + getY() * other.getY() + getZ() * other.getZ();
}

Vector Vector::cross(Vector& other) {
    return Vector(
        getY() * other.getZ() - getZ() * other.getY(),
        getZ() * other.getX() - getX() * other.getZ(),
        getX() * other.getY() - getY() * other.getX());
}
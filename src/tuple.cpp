#include "tuple.h"

Tuple::Tuple() {
    x_ = 0.0;
    y_ = 0.0;
    z_ = 0.0;
    w_ = 0;
}

Tuple::Tuple(double x, double y, double z, int w) {
    x_ = x;
    y_ = y;
    z_ = z;
    w_ = w;
}

Tuple Tuple::operator+(const Tuple& other) {
    return Tuple(
        x_ + other.x_,
        y_ + other.y_,
        z_ + other.z_,
        w_ + other.w_);
}

Tuple Tuple::operator-(const Tuple& other) {
    return Tuple(
        x_ - other.x_,
        y_ - other.y_,
        z_ - other.z_,
        w_ - other.w_);
}

Tuple Tuple::neg() {
    return Tuple() - *this;
}

Tuple Tuple::scale(double c) {
    return Tuple(x_ * c, y_ * c, z_ * c, w_ * c);
}
#include "color.h"

Color::Color() : Tuple(0.0, 0.0, 0.0, 0) { };

Color::Color(double r, double g, double b) : Tuple(r, g, b, 0) { };

Color Color::operator*(Color& other) {
    return Color(
        getX() * other.getX(),
        getY() * other.getY(),
        getZ() * other.getZ());
}
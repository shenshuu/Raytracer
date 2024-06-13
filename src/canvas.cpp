#include "canvas.h"

Canvas::Canvas() {
    width_ = 400;
    height_ = 300;
    canvas_ = std::vector<std::vector<Color> >(height_, std::vector<Color>(width_));
}

Canvas::Canvas(int width, int height) {
    width_ = width;
    height_ = height;
    canvas_ = std::vector<std::vector<Color> >(height_, std::vector<Color>(width_));
}

void Canvas::write_pixel(int r, int c, Color color) {
    canvas_[r][c] = color;
}

Color Canvas::pixel_at(int r, int c) {
    return canvas_[r][c];
}
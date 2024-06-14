#include "utilities.h"
#include "canvas.h"
#include <iostream>
#include <fstream>

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

void Canvas::to_ppm() {
    std::ofstream output;
    int r, g, b;    
    
    output.open("canvas.ppm");

    output << "P3\n";
    output << width_ << " " << height_ << '\n';
    output << "255" << '\n';

    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            Color c = pixel_at(i, j);
            r = max_int((int) min_double(c.getX() * 255, 255), 0);
            g = max_int((int) min_double(c.getY() * 255, 255), 0);
            b = max_int((int) min_double(c.getZ() * 255, 255), 0);
            output << r << " " << g << " " << b << " ";
            if (j > 0 && j % 4 == 0)
                output << '\n';
        }
    }
    output.close();
}
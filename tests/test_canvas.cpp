#include "../src/canvas.h"
#include "../src/color.h"
#include <iostream>
#include <cassert>

void test_canvas_write() {
    Canvas canvas(20, 10);
    Color color(0.2, 0.7, 0.3);
    canvas.write_pixel(3, 4, color);

    assert(canvas.pixel_at(3, 4) == color);

    std::cout << "test_canvas_write passed." << std::endl;
}
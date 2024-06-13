#include "../src/color.h"
#include <iostream>
#include <cassert>

void test_add_color() {
    Color c1(0.9, 0.6, 0.75);
    Color c2(0.7, 0.1, 0.25);

    assert(c1 + c2 == Color(1.6, 0.7, 1.0));

    std::cout << "test_add_color passed." << std::endl;
}


void test_scale_color() {
    Color c(0.2, 0.3, 0.4);
    
    assert(c.scale(2) == Color(0.4, 0.6, 0.8));

    std::cout << "test_scale_color passed." << std::endl;
}
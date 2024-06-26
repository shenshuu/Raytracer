#include "test_tuple.cpp"
#include "test_vector.cpp"
#include "test_color.cpp"
#include "test_canvas.cpp"
#include "test_matrix.cpp"
#include "../src/canvas.h"

int main() {
    // tuple tests
    test_create_tuple();
    test_add_tuple();
    test_sub_tuple();
    test_neg_tuple();

    // vector tests
    test_mag_vector();
    test_norm_vector();
    test_dot_vector();

    // color tests
    test_add_color();
    test_scale_color();

    // canvas tests
    test_canvas_write();

    Canvas canvas(5, 3);
    canvas.write_pixel(0, 0, Color(1.5, 0.0, 0.0));
    canvas.write_pixel(2, 1, Color(0.0, 0.5, 0.0));
    canvas.write_pixel(2, 4, Color(-0.5, 0.0, 1.0));
    canvas.to_ppm();

    // matrix tests
    test_create_matrix();
    test_matrix_equality();
    test_matrix_multiplication();
    test_matrix_identity();
    test_matrix_transpose();
    test_submatrix();
    test_matrix_minor();
    test_matrix_cofactor();
    test_matrix_determinant();
    test_matrix_invertability();
    test_matrix_inverse();

    return 0;
}
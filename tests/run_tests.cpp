#include "test_tuple.cpp"
#include "test_vector.cpp"
#include "test_color.cpp"

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
    // test_sub_color();
    test_scale_color();
    return 0;
}
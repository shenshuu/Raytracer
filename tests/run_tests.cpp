#include "test_tuple.cpp"
#include "test_vector.cpp"

int main() {
    // tuple tests
    test_create_tuple();
    test_add_tuple();
    test_sub_tuple();
    test_neg_tuple();

    // vector tests
    test_mag_vector();
    return 0;
}
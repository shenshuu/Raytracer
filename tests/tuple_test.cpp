#include "../src/tuple.h"
#include "../src/utilities.cpp"
#include <iostream>
#include <cassert>

void test_create_tuple() {
    Tuple tuple(1.0, 4.3, 3.2, 0);
    assert(check_equal(tuple.getX(), 1.0));
    assert(check_equal(tuple.getY(), 4.3));
    assert(check_equal(tuple.getZ(), 3.2));
    assert(check_equal(tuple.getW(), 0));
    // std::cout << "test_create_tuple passed." << std::endl;
}

void test_add_tuple() {
    Tuple t1(1.0, 2.0, 3.0, 0);
    Tuple t2(3.0, 4.0, 5.3, 0);
    Tuple t3 = t1 + t2;
    
    assert(check_equal(t3.getX(), 4.0));
    assert(check_equal(t3.getY(), 6.0));
    assert(check_equal(t3.getZ(), 8.3));
    assert(check_equal(t3.getW(), 0));
    // std::cout << "test_add_tuple passed." << std::endl;
}

int main() {
    test_create_tuple();
    test_add_tuple();
    return 0;
}
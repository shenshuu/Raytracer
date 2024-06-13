#include "../src/tuple.h"
#include "../src/utilities.h"
#include <iostream>
#include <cassert>

void test_create_tuple() {
    Tuple tuple(1.0, 4.3, 3.2, 0);

    assert(check_equal(tuple.getX(), 1.0));
    assert(check_equal(tuple.getY(), 4.3));
    assert(check_equal(tuple.getZ(), 3.2));
    assert(tuple.getW() == 0);
    
    // std::cout << "test_create_tuple passed." << std::endl;
}

void test_add_tuple() {
    Tuple t1(1.0, 2.0, 3.0, 0);
    Tuple t2(3.0, 4.0, 5.3, 0);
    Tuple t3 = t1 + t2;
    
    assert(check_equal(t3.getX(), 4.0));
    assert(check_equal(t3.getY(), 6.0));
    assert(check_equal(t3.getZ(), 8.3));
    assert(t3.getW() == 0);
    // std::cout << "test_add_tuple passed." << std::endl;
}

void test_sub_tuple() {
    Tuple t1(3.0, 2.0, 1.0, 1);
    Tuple t2(5.0, 6.0, 7.0, 1);
    Tuple t3 = t1 - t2;

    assert(check_equal(t3.getX(), -2.0));
    assert(check_equal(t3.getY(), -4.0));
    assert(check_equal(t3.getZ(), -6.0));
    assert(t3.getW() == 0);

    // std::cout << "test_sub_tuple passed." << std::endl;
}

void test_neg_tuple() {
    Tuple t1(1.0, 2.0, 3.0, 0);
    Tuple t2 = t1.neg();

    assert(check_equal(t2.getX(), -1.0));
    assert(check_equal(t2.getY(), -2.0));
    assert(check_equal(t2.getZ(), -3.0));
    assert(t2.getW() == 0);

    // std::cout << "test_neg_tuple passed." << std::endl;
}

void test_scale_tuple() {
    Tuple t1 = Tuple(1.0, 2.0, 7.3, 0);
    Tuple t2 = t1.scale(3.0);

    assert(check_equal(t2.getX(), 3.0));
    assert(check_equal(t2.getY(), 6.0));
    assert(check_equal(t2.getZ(), 21.9));
    assert(t2.getW() == 0);

    // std::cout << "test_scale_tuple passed." << std::endl;
}
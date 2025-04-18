#include <cassert>
#include <iostream>
#include "mylib.h"
using namespace std;

void test_rectangle_area_tc1() {    // passed
    Rectangle rectangle(2, 5);
    assert(rectangle.Area() == 10);
}

void test_rectangle_area_tc2() {    // failed
    Rectangle rectangle(2, 4);
    assert(rectangle.Area() == 12);
}

int main() {
    test_rectangle_area_tc1();
    // test_rectangle_area_tc2();
    std::cout << "All tests are executed!" << std::endl;
    return 0;
}

// Command to run ctest: ctest -C Debug --verbose
#include <iostream>
#include "calculator.h"

int main() {
    int a = 10, b = 5;

    std::cout << "Addition: " << Calculator::add(a, b) << std::endl;
    std::cout << "Subtraction: " << Calculator::subtract(a, b) << std::endl;
    std::cout << "Multiplication: " << Calculator::multiply(a, b) << std::endl;
    std::cout << "Division: " << Calculator::divide(a, b) << std::endl;

    return 0;
}
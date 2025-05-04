#include <iostream>
#include <bitset>
using namespace std;

// The size of the short type is 16 bits (or 2 bytes) regardless of whether you are on a 32-bit or 64-bit operating system.
#define BIT_COUNT_FOR_A_SHORT   16

unsigned short AND(unsigned short value1, unsigned short value2) {
    return value1 & value2;
}

unsigned short OR(unsigned short value1, unsigned short value2) {
    return value1 | value2;
}

unsigned short XOR(unsigned short value1, unsigned short value2) {
    return value1 ^ value2;
}

unsigned short NOT(unsigned short value) {
    return ~value;
}

unsigned short LogicalLeftShift(unsigned short value, unsigned short count) {
    return value << count;
}

unsigned short LogicalRightShift(unsigned short value, unsigned short count) {
    return value >> count;
}

unsigned short RotateLeftShift(unsigned short value, unsigned short count) {
    return (value << count) | (value >> (sizeof(value) * BIT_COUNT_FOR_A_SHORT - count));
}

unsigned short RotateRightShift(unsigned short value, unsigned short count) {
    return (value >> count) | (value << (sizeof(value) * BIT_COUNT_FOR_A_SHORT - count));
}

short ArithmeticLeftShift(short value, short count) {
    return value << count;
}

short ArithmeticRightShift(short value, short count) {
    return value >> count;
}

int main() {
    std::bitset<BIT_COUNT_FOR_A_SHORT> binary;

    binary = AND(0b0101, 0b0011);
    std::cout << "AND: 0b" << binary << std::endl;

    binary = OR(0b0101, 0b0011);
    std::cout << "OR: 0b" << binary << std::endl;

    binary = XOR(0b0101, 0b0011);
    std::cout << "XOR: 0b" << binary << std::endl;

    binary = NOT(0b0101);
    std::cout << "NOT: 0b" << binary << std::endl;

    // Logical shift //
    binary = LogicalLeftShift(0b0101, 1);
    std::cout << "LogicalLeftShift: 0b" << binary << std::endl;

    binary = LogicalLeftShift(0b0111, 1);
    std::cout << "LogicalLeftShift: 0b" << binary << std::endl;

    binary = LogicalLeftShift(0b1111, 1);
    std::cout << "LogicalLeftShift: 0b" << binary << std::endl;

    binary = LogicalRightShift(0b0101, 1);
    std::cout << "LogicalRightShift: 0b" << binary << std::endl;

    binary = LogicalRightShift(0b0111, 1);
    std::cout << "LogicalRightShift: 0b" << binary << std::endl;

    binary = LogicalRightShift(0b1111, 1);
    std::cout << "LogicalRightShift: 0b" << binary << std::endl;


    // Rotate shift //
    binary = RotateLeftShift(0b0101, 1);
    std::cout << "RotateLeftShift: 0b" << binary << std::endl;

    binary = RotateLeftShift(0b0111, 1);
    std::cout << "RotateLeftShift: 0b" << binary << std::endl;

    binary = RotateLeftShift(0b1111, 1);
    std::cout << "RotateLeftShift: 0b" << binary << std::endl;

    binary = RotateRightShift(0b0101, 1);
    std::cout << "RotateRightShift: 0b" << binary << std::endl;

    binary = RotateRightShift(0b0111, 1);
    std::cout << "RotateRightShift: 0b" << binary << std::endl;

    binary = RotateRightShift(0b1111, 1);
    std::cout << "RotateRightShift: 0b" << binary << std::endl;


    // Arithmetic shift //
    binary = ArithmeticLeftShift(0b0001, 1);
    std::cout << "ArithmeticLeftShift: 0b" << binary << std::endl;

    binary = ArithmeticLeftShift(0b0010, 1);
    std::cout << "ArithmeticLeftShift: 0b" << binary << std::endl;

    binary = ArithmeticLeftShift(0b0011, 1);
    std::cout << "ArithmeticLeftShift: 0b" << binary << std::endl;

    binary = ArithmeticLeftShift(0b1111, 1);
    std::cout << "ArithmeticLeftShift: 0b" << binary << std::endl;

    binary = ArithmeticRightShift(0b0001, 1);
    std::cout << "ArithmeticRightShift: 0b" << binary << std::endl;

    binary = ArithmeticRightShift(0b0010, 1);
    std::cout << "ArithmeticRightShift: 0b" << binary << std::endl;

    binary = ArithmeticRightShift(-11, 1);       // 0b1011
    std::cout << "ArithmeticRightShift: 0b" << binary << std::endl;

    binary = ArithmeticRightShift(-12, 1);       // 0b1100
    std::cout << "ArithmeticRightShift: 0b" << binary << std::endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <cstring>  // memcpy
#include <cstdint>  // uint8_t

int main() {
    // Create a vector
    std::vector<uint8_t> vec;

    // Initialize all items in vector to 0
    std::fill(vec.begin(), vec.end(), 0U);

    // Allocate memory for vector. Maximum is 5 items
    int VEC_SIZE = 5;
    vec.resize(VEC_SIZE);   // NOTE: Without this, segmentation fault at memcpy()!

    // Copy data to vector
    uint8_t buffer[] = {'a', 'b', 'c', 'x', 'y'};
    std::memcpy(vec.data(), buffer, VEC_SIZE);

    // Display size and capacity
    std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;

    // Display elements using data buffer
    std::cout << "Display buffer in vector: 0x";
    const uint8_t* pbuffer = vec.data();
    for (int i = 0; i < vec.size(); i++) {
        printf("%02X", pbuffer[i]);     // NOTE: uin8_t cannot be used with std::count
    }
    std::cout << std::endl;

    return 0;
}

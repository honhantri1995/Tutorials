#include <iostream>
#include <array>
#include <algorithm>

int main() {
    // Create and initialize a std::array
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    // Access elements using at() and operator[]
    std::cout << "Element at index 2 using at(): " << arr.at(2) << std::endl;
    std::cout << "Element at index 2 using operator[]: " << arr[2] << std::endl;

    // Access first and last elements
    std::cout << "First element: " << arr.front() << std::endl;
    std::cout << "Last element: " << arr.back() << std::endl;

    // Size of the array
    std::cout << "Size of array: " << arr.size() << std::endl;

    // Fill the array
    arr.fill(0);
    std::cout << "Array after fill(0): ";
    for (const auto& value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Swap with another array
    std::array<int, 5> otherArr = {10, 20, 30, 40, 50};
    arr.swap(otherArr);
    std::cout << "Array after swap: ";
    for (const auto& value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Using std::for_each to print the array
    std::cout << "Using for_each to print elements: ";
    std::for_each(arr.begin(), arr.end(), [](int value) {
        std::cout << value << " ";
    });
    std::cout << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Create a vector and add elements
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(5);

    // Display size and capacity
    std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;

    // Insert an element at index 2
    auto itr = vec.begin();
    vec.insert(itr + 2, 3);

    // Display elements using range-based for loop
    std::cout << "Elements after insert(): ";
    for (const auto& value : vec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Remove the last element
    vec.pop_back();
    // Remove element at index 2
    vec.erase(vec.begin() + 2);

    // Display elements using traditional for loop
    std::cout << "Elements after pop_back() and erase(): ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Clear the vector
    vec.clear();
    std::cout << "Size after clear: " << vec.size() << std::endl;

    // Refill the vector
    vec = {1, 2, 3, 4, 5};

    // Resize the vector and fill with 0
    vec.resize(10, 0);

    // Display elements using std::for_each
    std::cout << "Elements after resize: ";
    std::for_each(vec.begin(), vec.end(), [](int value) {
        std::cout << value << " ";
    });
    std::cout << std::endl;

    // Display first and last element
    std::cout << "First element: " << vec.front() << ", last elemement: " << vec.back() << std::endl;

    return 0;
}

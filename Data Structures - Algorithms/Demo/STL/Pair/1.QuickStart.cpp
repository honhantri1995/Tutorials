#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int main() {
    // Create a vector of pairs
    std::vector<std::pair<int, std::string>> vec;

    // Insert pairs into the vector
    vec.emplace_back(1, "Apple");
    vec.emplace_back(3, "Banana");
    vec.emplace_back(2, "Cherry");

    // Display the pairs
    std::cout << "Pairs in the vector:" << std::endl;
    for (const auto& p : vec) {
        std::cout << "First: " << p.first << ", Second: " << p.second << std::endl;
    }

    // Sort the vector of pairs based on the first element
    std::sort(vec.begin(), vec.end());

    // Display sorted pairs
    std::cout << "\nSorted pairs:" << std::endl;
    for (const auto& p : vec) {
        std::cout << "First: " << p.first << ", Second: " << p.second << std::endl;
    }

    // Compare pairs
    std::pair<int, std::string> p1(1, "Apple");
    std::pair<int, std::string> p2(1, "Apple");

    if (p1 == p2) {
        std::cout << "\nThe pairs p1 and p2 are equal." << std::endl;
    }

    return 0;
}

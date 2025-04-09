#include <iostream>
#include <list>
#include <algorithm>

int main() {
    // Create and initialize a std::list
    std::list<int> lst = {3, 1, 4, 1, 5};

    // Add elements
    lst.push_back(9);
    lst.push_front(2);

    // Display elements
    std::cout << "List after adding elements: ";
    for (const auto& value : lst) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Remove elements
    lst.pop_back();
    lst.pop_front();
    std::cout << "List after popping elements: ";
    for (const auto& value : lst) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
 
    // Insert an element
    lst.insert(std::next(lst.begin(), 1), 6);
    std::cout << "List after inserting 6: ";
    for (const auto& value : lst) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Sort the list
    lst.sort();
    std::cout << "Sorted list in ascending: ";
    for (const auto& value : lst) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Sort the list in descending order
    lst.sort([](int a, int b) {
        return a > b;
    });
    std::cout << "Sorted list in descending order: ";
    for (const auto& value : lst) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Clear the list
    lst.clear();
    std::cout << "List size after clear: " << lst.size() << std::endl;

    return 0;
}

#include <iostream>
#include <unordered_set>
#include <algorithm>

int main() {
    // Create and initialize a std::unordered_set
    std::unordered_set<int> mySet = {5, 3, 8, 1, 1, 4};

    // Insert an element
    mySet.insert(10);
    std::cout << "Set after insertion: ";
    for (const auto& value : mySet) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Remove an element
    mySet.erase(3);
    std::cout << "Set after erasing 3: ";
    for (const auto& value : mySet) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Check if an element exists
    auto it = mySet.find(8);
    if (it != mySet.end()) {
        std::cout << "Found 8 in the set." << std::endl;
    } else {
        std::cout << "8 not found in the set." << std::endl;
    }

    // Count elements
    size_t count = mySet.count(10);
    std::cout << "Count of 10 in the set: " << count << std::endl;

    // Display size and check if empty
    std::cout << "Size of the set: " << mySet.size() << std::endl;
    std::cout << "Is the set empty? " << (mySet.empty() ? "Yes" : "No") << std::endl;

    // Create another set called anotherSet, then assign the elements from mySet to anotherSet
    std::unordered_set<int> anotherSet(mySet.begin(), mySet.end());
    std::cout << "New set is: ";
    for (auto it = anotherSet.begin(); it != anotherSet.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Clear the set
    mySet.clear();
    std::cout << "Size of the set after clearing: " << mySet.size() << std::endl;

    return 0;
}

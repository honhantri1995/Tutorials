#include <iostream>
#include <set>
#include <algorithm>

int main() {
    // Create and initialize a std::set
    std::set<int> mySet = {5, 3, 8, 1, 1, 4};

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

    // Lower and upper bounds
    auto lower = mySet.lower_bound(4);
    auto upper = mySet.upper_bound(4);
    std::cout << "Lower bound of 4: " << (lower != mySet.end() ? *lower : -1) << std::endl;
    std::cout << "Upper bound of 4: " << (upper != mySet.end() ? *upper : -1) << std::endl;


    // Create another set called anotherSet, then assign the elements from mySet to anotherSet
    std::set<int> anotherSet(mySet.begin(), mySet.end());
    std::cout << "New set is: ";
    for (auto it = anotherSet.begin(); it != anotherSet.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Remove all elements less than 5 in set
    std::cout << "Set after removal of elements less than 5: ";
    mySet.erase(mySet.begin(), mySet.find(5));
    for (it = mySet.begin(); it != mySet.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Clear the set
    mySet.clear();
    std::cout << "Size of the set after clearing: " << mySet.size() << std::endl;

    return 0;
}

#include <iostream>
#include <deque>

int main() {
    std::deque<int> myDeque;

    // Adding elements
    myDeque.push_back(10);
    myDeque.push_front(5);
    myDeque.push_back(15);
    myDeque.push_front(1);

    std::cout << "Deque elements: ";
    for (const auto& elem : myDeque) {
        std::cout << elem << " "; // Outputs: 1 5 10 15
    }
    std::cout << std::endl;

    // Accessing front and back elements
    std::cout << "Front element: " << myDeque.front() << std::endl; // Outputs: 1
    std::cout << "Back element: " << myDeque.back() << std::endl;   // Outputs: 15

    // Removing elements
    myDeque.pop_front();
    myDeque.pop_back();

    std::cout << "Deque after popping: ";
    for (const auto& elem : myDeque) {
        std::cout << elem << " "; // Outputs: 5 10
    }
    
    std::cout << std::endl;
    std::cout << "Size of deque: " << myDeque.size() << std::endl; // Outputs: 2

    return 0;
}

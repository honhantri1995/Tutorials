#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;

    // Pushing elements onto the queue
    myQueue.push(5);
    myQueue.push(10);
    myQueue.push(15);
    myQueue.push(20);

    std::cout << "Queue size: " << myQueue.size() << std::endl;

    // Accessing the front and back elements
    std::cout << "Front element: " << myQueue.front() << std::endl;
    std::cout << "Back element: " << myQueue.back() << std::endl;

    // Popping elements from the queue
    std::cout << "Popping elements: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;

    std::cout << "Queue size after popping: " << myQueue.size() << std::endl;

    return 0;
}

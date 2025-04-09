#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack;

    // Pushing elements onto the stack
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);
    myStack.push(20);

    std::cout << "Stack size: " << myStack.size() << std::endl;

    // Accessing the top element
    std::cout << "Top element: " << myStack.top() << std::endl;

    // Popping elements from the stack
    std::cout << "Popping elements: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    std::cout << "Stack size after popping: " << myStack.size() << std::endl;

    return 0;
}

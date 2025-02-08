#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int element) {
        Node* newNode = new Node(element);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow!" << std::endl;
            return -1; // Error value
        }

        Node* temp = top;
        int topElement = top->data;
        top = top->next;
        delete temp;
        return topElement;
    }

    int peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1; // Error value
        }

        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    int size() const {
        int count = 0;
        Node* current = top;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Stack size: " << stack.size() << std::endl;

    while (!stack.isEmpty()) {
        std::cout << "Top element: " << stack.peek() << std::endl;
        stack.pop();
    }

    return 0;
}
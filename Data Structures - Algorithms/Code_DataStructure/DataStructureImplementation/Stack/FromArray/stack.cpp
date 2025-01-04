#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000

class Stack
{
private:
	int top;					// Index of the top item

public:
	int arr[MAX_SIZE];			// Maximum size of Stack

	Stack() {
		top = -1;
	}

	bool push(int x) {
		if (isFull()) {
			cout << "Stack Overflow";
			return false;
		}
		else {
			arr[++top] = x;
			cout << x << " pushed into stack\n";
			return true;
		}
	}

	int pop() {
		if (top < 0) {
			cout << "Stack Underflow";
			return 0;
		}
		else {
			int x = arr[top--];
			return x;
		}
	}

	int peek() {
		if (isEmpty()) {
			cout << "Stack is Empty";
			return 0;
		}
		else {
			int x = arr[top];
			return x;
		}
	}

	bool isEmpty() { return (top < 0); }

	bool isFull() { return (top >= (MAX_SIZE - 1)); }
};

int main()
{
	class Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	
	// print top element of stack after popping
	cout << "Top element is: " << s.peek() << endl;
	
	// print all elements in stack:
	cout << "Elements present in stack: ";
	while(!s.isEmpty()) {
		cout << s.peek() <<" ";
		s.pop();
	}

	return 0;
}

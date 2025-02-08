using System;

namespace ImplementStack
{
class Stack
{
	private int[] arr;
	private int top;			// Index of the top item
	private int max_size;

	public Stack(int size)
	{
		arr = new int[size]; 	// Maximum size of Stack
		top = -1;
		max_size = size;
	}

	public void push(int item)
	{
		if (top == max_size - 1) {
			Console.WriteLine("Stack Overflow");
			return;
		}
		else {
			arr[++top] = item;
		}
	}

	public int pop()
	{
		if (top == -1) {
			Console.WriteLine("Stack is Empty");
			return -1;
		}
		else {
			Console.WriteLine("{0} popped from stack ", arr[top]);
			return arr[top--];
		}
	}

	public int peek()
	{
		if (top == -1) {
			Console.WriteLine("Stack is Empty");
			return -1;
		}
		else {
			Console.WriteLine("{0} popped from stack ", arr[top]);
			return arr[top];
		}
	}

	public void printStack()
	{
		if (top == -1) {
			Console.WriteLine("Stack is Empty");
			return;
		}
		else {
			for (int i = 0; i <= top; i++) {
				Console.WriteLine("{0} pushed into stack", arr[i]);
			}
		}
	}
}

// Driver program to test above functions
class Program
{
	static void Main()
	{
		Stack p = new Stack(5);

		p.push(10);
		p.push(20);
		p.push(30);
		p.printStack();
		p.pop();
	}
}
}

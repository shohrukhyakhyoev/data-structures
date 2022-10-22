#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
	static const int limit = 10;
	int stack[limit];
	int top = -1;
public:

	bool isEmpty() {
		if (top == -1)
			return true;
		return false;
	}

	void Push(int x) {
		if (top == limit - 1) {
			cout << "\nError: stack overflow." << endl;
		} else {
            stack[++top] = x;
        }
	}

	void Pop() {
		if (top == -1) {
			cout << "\nError: No element to pop. Stack is empty." << endl;
		} else {
            top--; // this means top now points to one before element, so last element is now out of stack.
            // when we Push later, value there will be modified.
        }
	}

	int Top() {
		return stack[top]; // returns value on top of the stack.
	}

	void printStack() {
		for (int i = 0; i <= top; i++) {
			cout << stack[i] << "  ";
		}
		cout << endl << endl;
	}
};

int main() {

	Stack s;
	int x;

	for (int j = 0; j < 5; j++) {
		cout << "Input number: ";
		cin >> x;

		s.Push(x);
	}

	cout << endl;

	s.printStack();

	s.Pop();

	s.printStack();

	return 0;
}
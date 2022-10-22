#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Stack_LL {
private:
	int data;
	Stack_LL* top = NULL;
	Stack_LL* link = NULL;

public:

	 // USING STACK TO REVERSE LINKED LIST:

	void reverseLinkedList() {      // using STACK.
		stack<Stack_LL*>S;
		Stack_LL* temp = top;

		if (!top)
			return;

		while (temp != NULL) {
			S.push(temp);
			temp = temp->link;
		}

		temp = S.top();
		top = temp;
		S.pop();

		while (!S.empty()) {
			temp->link = S.top();
			S.pop();
			temp = temp->link;
		}
		temp->link = NULL;
	}

	void Push(int x) {
        Stack_LL* new_node = new Stack_LL();
        new_node->data = x;
         if (top == NULL) { // if stack is empty
             new_node->link = NULL;
             top = new_node;
         }
		new_node->link = top;
		top = new_node;
	}


	void Pop() {
		Stack_LL* temp;
		if (top == NULL) {
			return;
		}
		temp = top;
		top = top->link;
		delete(temp);
	}

	int Top() {
		return top->data;
	}

	bool isEmpty() {
		if (top == NULL)
			return true;
		return false;
	}

	void printStack() {
		Stack_LL* temp = top;
		while (temp != NULL) {
			cout << temp->data << "  ";
			temp = temp->link;
		}
	}
};


int main() {

	Stack_LL* s = new Stack_LL();
	int x = 0;

	for (int j = 0; j < 5; j++) {
		cout << "Input value - ";
		cin >> x;

		s->Push(x);
	}

	cout << endl;

	s->printStack();
	cout << endl;

	s->reverseLinkedList();

	s->printStack();
	cout << endl;

	s->Pop();

	s->printStack();
	cout << endl;

	system("pause");
	return 0;
}
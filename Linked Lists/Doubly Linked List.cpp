#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node* previous;

    Node(int data) {
        this->data = data;
        next = nullptr;
        previous = nullptr;
    }
};


class DoublyLinkedList {
public:

    static void insertAtStart(Node** head, int value) {
        Node* cur = *head;
        Node* newNode = new Node(value); // creating new node
        if (cur) {
            cur->previous = newNode; newNode->previous = nullptr; newNode->next = *head;
        }
        *head = newNode;
    }

    static void insertBetween(Node** head, int position, int value) {
        Node* cur = *head;
        Node* new_node = new Node(value), *prev = nullptr;
        int index = 1, max = length(*head);
        while (position > max && position <= 0) {
            cout << "\nPosition is out of Range. Try again" << endl; cout << "Position: ";
            cin >> position;
        }
        if (position == 1 || cur == nullptr) { insertAtStart(head, value);
        } else if (position == max) { insertAtEnd(head, value);
        } else {
            while (true) {
                if (index == position) {
                    new_node->next = cur; new_node->previous = prev; cur->previous = new_node; prev->next = new_node; break;
                }
                prev = cur;
                cur = cur->next; index++;
            }
        }
    }

    static void insertAtEnd(Node** head, int value) {
        Node* cur = *head;
        Node* new_node = new Node(value);
        if (!cur) {
            insertAtStart(head, value);
        }

        while (cur->next != nullptr) {
            cur = cur->next;
        }

        cur->next = new_node;
        new_node->next = nullptr;
        new_node->previous = cur;

    }

    static void deleteAtBeg(Node** head) {
        Node* cur = *head;
        if (!cur) {
            cout<<"Underflow"<<endl;
        }
        Node* temp = cur;
        *head = cur->next;
        (cur->next)->previous = nullptr;
        delete(temp);

    }

    static void deleteBetween(Node** head, int position) {
        Node* cur = *head;
        Node* prev = nullptr;
        int index = 1, max = length(*head);
        while (position > max && position <= 0) {
            cout << "\nPosition is out of Range. Try again" << endl; cout << "Position: ";
            cin >> position;
        }
        if (!cur) {
            cout<<"Underflow"<<endl; return;
        }
        if (position == 1) {
            deleteAtBeg(head);
        } else if (position == max) {
            deleteAtEnd(head);
        } else {
            while (true) {
                if (index == position) {
                    Node* temp = cur; prev->next = cur->next; delete(temp);
                    break;
                }
                prev = cur;
                cur = cur->next; index++;
            }
        }
    }

    static void deleteAtEnd(Node** head) {
        Node* cur = *head, *prev = nullptr;
        if (!cur) {
            cout<<"Underflow"<<endl; return;
        }
        while (cur->next != nullptr) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = nullptr;
        Node* temp = cur->next; delete(temp);
    }

    static int length(Node* head) {
        int count = 1;
        while (head != nullptr) {
            head = head->next; count++;
        }
        return count;
    }


    static void print(Node* head) {
        if (!head) {
            return;
        }
        cout<<head->data<<" ";
        print(head->next);
    }
};

int main() {

    int position, value;

    Node* head = new Node(2);
    DoublyLinkedList::insertAtStart(&head, 1);
    DoublyLinkedList::insertAtEnd(&head, 4);
    DoublyLinkedList::insertBetween(&head, 3, 3);

    cout<<"Initial Linked List: ";
    DoublyLinkedList::print(head);

    cout<<"\n\nValue to insert at start: ";
    cin>>value;
    DoublyLinkedList::insertAtStart(&head, value);
    DoublyLinkedList::print(head);

    cout<<"\n\nEnter position to insert a new value: ";
    cin>>position;
    cout<<"Value: ";
    cin>>value;
    DoublyLinkedList::insertBetween(&head, position, value);
    DoublyLinkedList::print(head);

    cout<<"\n\nValue to insert at end: ";
    cin>>value;
    DoublyLinkedList::insertAtEnd(&head, value);
    DoublyLinkedList::print(head);

    cout<<"\n\nValue is being deleted at start ... \n";
    DoublyLinkedList::deleteAtBeg(&head);
    DoublyLinkedList::print(head);

    cout<<"\n\nEnter position to delete a new value: ";
    cin>>position;
    DoublyLinkedList::deleteBetween(&head, position);
    DoublyLinkedList::print(head);

    cout<<"\n\nValue is being deleted at end ... ";
    DoublyLinkedList::deleteAtEnd(&head);

    cout<<"\n\nFinal linked List: ";
    DoublyLinkedList::print(head);

    cout<<"\\n"<<endl;

    return 0;
}

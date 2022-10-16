/**
 * Created by Shohrukhbek Yakhyoev on date: 16/10/2022
 * Description: Implementation of Singly Linked Lists in C++
 */

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class SinglyLinkedList {
public:

    static void insertAtStart(Node** head, int value) {
        Node* newNode = new Node(value);

        if (!*head) {
            *head = newNode;
        } else {
            newNode->next = *head;
            *head = newNode;
        }
    }

    static void insertBetween(Node** head, int position, int value) {
        Node* cur = *head;
        Node* prev = nullptr, *newNode = new Node(value);

        int index = 1, max = length(*head);

        while (position > max || position <= 0) {
            cout<<"Position is out of range. Try again"<<endl;
            cin>>position;
        }

        if (cur == nullptr || position == 1) {
            insertAtStart(head, value);
            return;
        }

        if (position == max) {
            insertAtEnd(head, value);
            return;
        }

        while (true) {

            if (position == index) {
                newNode->next = cur;
                prev->next = newNode;
                break;
            }

            prev = cur;
            cur = cur->next;
            index++;
        }


    }

    static void insertAtEnd(Node** head, int value) {
        Node* cur = *head;
        Node* newNode = new Node(value);

        if (!cur) {
            insertAtStart(head, value);
            return;
        }

        while (true) {

            if (cur->next == nullptr) {
                newNode->next = nullptr;
                cur->next = newNode;
                break;
            }
            cur = cur->next;
        }
    }

    static void deleteAtBeg(Node** head) {
        Node* cur = *head;

        if (!cur) {
            cout<<"Underflow"<<endl;
            return;
        }

        Node* temp = cur;
        *head = cur->next;
        delete(temp);
    }

    static void deleteBetween(Node** head, int position) {
        Node* cur = *head;
        Node* prev = nullptr;

        int index = 1, max = length(*head);

        if (!cur) {
            cout<<"Underflow"<<endl;
            return;
        }

        while (position > max || position <= 0) {
            cout<<"Position is out of range. Try again"<<endl;
            cin>>position;
        }

        if (position == 1) {
            deleteAtBeg(head);
            return;
        }

        if (position == max) {
            deleteAtEnd(head);
            return;
        }

        while (true) {

            if (position == index) {
                Node *temp = cur;
                prev->next = cur->next;
                delete (temp);
            }

            prev = cur;
            cur = cur->next;
            index++;
        }
    }

    static void deleteAtEnd(Node** head) {
        Node* cur = *head;
        Node* prev = nullptr;

        if (!cur) {
            cout<<"Underflow"<<endl;
            return;
        }

        while (cur->next != nullptr) {
            prev = cur;
            cur = cur->next;
        }

        Node* temp = cur;
        prev->next = nullptr;
        delete(temp);

    }

    static int length(Node* head) {
        int counter = 0;
        Node* cur = head;

        while (!cur) {
            cur = cur->next;
            counter++;
        }

        return counter;
    }

    static void print(Node* head) {
        if (!head) {
            return; }
        cout << head->data << " ";
        print(head->next);
    }

};


int main() {

    int position, value;

    Node* head = new Node(2);
    SinglyLinkedList::insertAtStart(&head, 1);
    SinglyLinkedList::insertAtEnd(&head, 4);
    SinglyLinkedList::insertBetween(&head, 3, 3);

    cout<<"Initial Linked List: ";
    SinglyLinkedList::print(head);

    cout<<"\n\nValue to insert at start: ";
    cin>>value;
    SinglyLinkedList::insertAtStart(&head, value);
    SinglyLinkedList::print(head);

    cout<<"\n\nEnter position to insert a new value: ";
    cin>>position;
    cout<<"Value: ";
    cin>>value;
    SinglyLinkedList::insertBetween(&head, position, value);
    SinglyLinkedList::print(head);

    cout<<"\n\nValue to insert at end: ";
    cin>>value;
    SinglyLinkedList::insertAtEnd(&head, value);
    SinglyLinkedList::print(head);

    cout<<"\n\nValue is being deleted at start ... \n";
    SinglyLinkedList::deleteAtBeg(&head);
    SinglyLinkedList::print(head);

    cout<<"\n\nEnter position to delete a new value: ";
    cin>>position;
    SinglyLinkedList::deleteBetween(&head, position);
    SinglyLinkedList::print(head);

    cout<<"\n\nValue is being deleted at end ... ";
    SinglyLinkedList::deleteAtEnd(&head);

    cout<<"\n\nFinal linked List: ";
    SinglyLinkedList::print(head);

    cout<<"\n\n"<<endl;
    return 0;
}

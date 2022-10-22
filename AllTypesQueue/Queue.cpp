// Created by Shohrukh Yakhyoev, date: October 9, 2022

#include <iostream>
#include <cstdlib>
using namespace std;


class Queue{
    // abstract class (In java, it should be interface, as it just defines functions which Derived classes must implement
public:
    virtual void dequeue()=0;
    virtual void enqueue(int newVal)=0;
    virtual void traverse()=0;
};


class LinearQueueArray: public Queue {
protected:
    static const int limit = 10;
    int front;
    int rear;
    int queue[limit];

public:

    LinearQueueArray() : front(-1), rear(-1) {}


    void enqueue(int newVal) override {
        if (rear == limit-1) {
            // means rear is the rear most position, so cannot add new el.
            cout<<"Overflow: no memory space available for new element."<<endl;
        }
        if ((front == -1) || (front>rear)) {
            // queue is empty, so we should set both front & rear to 0
            front = rear = 0;
        }
        else {
            // usual case, we increment rear if no above conditions are met.
            rear += 1;
        }
        queue[rear] = newVal;
    }


    void dequeue() override {
        if (front == -1) {
            // means queue is empty, so nothing to delete then.
            cout<<"Underflow: no element to delete from queue. It is empty!"<<endl;
        }
        if (front == rear) {
            // means there is only one el left in queue. So we set front & rear to 0
            // which indicates then queue is empty
            front = rear = -1;
        }
        else{
            // usual case, we increment rear if no above conditions are met.
            front += 1;
        }
    }

    void traverse() override {
        for (int i=front; i<=rear; i++) {
            cout<<queue[i]<<"  ";
        }
        cout<<endl;
    }
};


class LinearQueueLinkedList: public Queue {
private:
    int val;
    LinearQueueLinkedList* front;
    LinearQueueLinkedList* rear;
    LinearQueueLinkedList* next;

public:

    LinearQueueLinkedList(int newVal=0): val(newVal), front(nullptr), rear(nullptr), next(nullptr) {
    }

    void enqueue(int newVal) override {
        LinearQueueLinkedList* newEl = new LinearQueueLinkedList(newVal);
        if (newEl == nullptr) {
            // means no memory is allocated. Hence: Overflow.
            cout<<"Overflow"<<endl;
        }
        if (front == nullptr) {
            front = rear = newEl;
            front->next = rear->next = nullptr;
        }
        else {
            rear->next = newEl;
            newEl->next = nullptr;
            rear = newEl;
        }
    }

    void dequeue() override {
        if (front == nullptr) {
            // means queue is empty, so nothing to delete!
            cout<<"Underflow"<<endl;
        }

        auto* temp = front;

        if (front == rear) {
            front = rear = nullptr;
        }
        else {
            front = front->next;
            delete(temp);
        }
    }

    void traverse() override {
        auto* temp = front;
        while (temp != nullptr) {
            cout<<temp->val<<"  ";
            temp = temp->next;
        }
        cout<<endl;
    }
};


class CircularQueue: public LinearQueueArray {
public:

    CircularQueue() {}

    void enqueue(int newVal) override {
        if ((front == 0 && rear == limit-1) || (front == rear + 1)) {
            // means queue is full! when front = 0, rear should be limit-1
            // for queue to be fulled. But in general, if front = x, rear should
            // be x+1. Ex: size is 10 and front is 7. If rear is 6, then queue is
            // said to be full.
            cout<<"Overflow"<<endl;
        }
        if (front == -1) {
            // if queue is empty, set front & rear to 0
            front = rear = 0;
        } else if (rear == limit-1) {
            // but front != 0, we have already checked it, so no need to override.
            // that means front is not at 0, so rear can go forward.
            rear = 0;
        } else {
            // usual case when we just increment rear if no conditions above are met.
            rear += 1;
        }

        queue[rear] = newVal;
    }

    void dequeue() override {
        if (front == -1) {
            // means queue is empty! So nothing to delete.
            cout<<"Underflow"<<endl;
        }
        if (front == rear) {
            // means there is only one el left in queue. So we set front & rear to 0
            // which indicates then queue is empty
            front = rear = -1;
        } else if (front == limit-1) {
            // if front is max index that means at 0 there is no el
            // thus front can be updated to 0 (which automatically leaves out prev
            // front at limit-1 index)
            front = 0;
        } else {
            // usual case when we just increment rear if no conditions above are met.
            // once front is updated, prev front is free cell.
            front += 1;
        }
    }

};


void testQueue(Queue* queue){

    // this loop adds 5 els to queue
    for (int j=1; j<6; j++) {
        queue->enqueue(j);
    }
    // displaying initial queue
    queue->traverse();
    cout<<endl;

    // enqueueing even & dequeueing odd nums
    for (int i=1; i<5; i++) {
        if (i%2 == 0) {
            cout<<"Inserting: "<< i<<endl;
            queue->enqueue(i);
        } else{
            cout<<"Deleting: "<<endl;
            queue->dequeue();
        }
        queue->traverse();
    }

    cout<<endl<<endl;
}



int main() {

    Queue* queue[] = {new LinearQueueArray(), new LinearQueueLinkedList(), new CircularQueue()};

    for (int i=0; i<sizeof(queue)/sizeof(*queue[0]); i++) {
        testQueue(queue[i]);
    }

    return 0;
}

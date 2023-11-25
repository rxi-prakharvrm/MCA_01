#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue {
    private:
    int front;
    int rear;
    int size;
    int *Q;

    public:
    Queue() {front = -1; rear = -1; size = 10; Q = new int[size];}
    Queue(int size) {front = -1; rear = -1; this->size = size; Q = new int[this->size];}
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x) {
    if(rear == size-1)
        cout << "Queue is full" << endl;
    else {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue() {
    int x = -1;
    if(front == rear)
        cout << "Queue is empty" << endl;
    else {
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::display() {
    for(int i = front+1; i <= rear; i++) {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main() {
    int size = 7;
    Queue *q = new Queue(size);

    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    q->enqueue(6);

    q->dequeue();

    q->display();

    return 0;
}
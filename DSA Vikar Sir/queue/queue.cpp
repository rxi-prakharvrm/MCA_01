#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<class T>
class Queue {
public:
    int front = -1;
    int rear = -1;
    int n = 100;
    int queue[100];

    bool isFull() {
        if(rear == n-1) {
            return true;
        } else {
            return false;
        }
    }

    bool isEmpty() {
        if(front == -1 && rear == -1) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(T data) {
        if(this->isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        } else {
            if(front == -1) {
                front++;
            }
            rear++;
            queue[rear] = data;
        }
    }

    void dequeue() {
        if(this->isEmpty() || front > rear) {
            cout << "Queue underflow!" << endl;
            return;
        } else {
            front++;
        }
    }

    void displayQueue() {
        if(front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        } else {
            cout << endl << "Queue elements are: " << endl;
            for(int i = front; i <= rear; i++) {
                cout << queue[i] << "->";
            }
            cout << "nullptr" << endl;
        }
    }
};

int main() {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.dequeue();

    q.displayQueue();
    return 0;
}
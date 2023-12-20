#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
    public:
    Node* front;
    Node* rear;

    Queue() : front(NULL), rear(NULL) {}

    void enqueue(int item) {
        Node* newNode = new Node(item);
        if(front == NULL && rear == NULL) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if(front == NULL && rear == NULL) {
            cout << "Queue Underflow!" << endl;
            return;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void display() {
        if(front == NULL && rear == NULL) {
            cout << "Nothing to display!" << endl;
            return;
        } else {
            Node* temp = front;
            while(temp != NULL) {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();
    q.dequeue();

    q.display();
    return 0;
}
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

class Stack {
    public:
    Node* top;

    Stack() : top(NULL) {}

    bool isEmpty() {
        if(top == NULL) return true;
        else return false;
    }

    void push(int item) {
        Node* newNode = new Node(item);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if(isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        } else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    int size() {
        int count = 0;
        if(top == NULL) {
            cout << "Stack is empty!" << endl;
            return 0;
        } else {
            Node* temp = top;
            while(temp != NULL) {
                count++;
                temp = temp->next;
            }
        }
        return count;
    }

    void display() {
        if(top == NULL) {
            cout << "Nothing to display!" << endl;
            return;
        } else {
            Node* temp = top;
            while(temp != NULL) {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
    
};

int main() {
    Stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    stk.pop();

    stk.display();

    cout << "Size of the stack is: " << stk.size() << endl;
    return 0;
}
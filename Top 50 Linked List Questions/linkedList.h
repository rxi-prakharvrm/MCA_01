#include <iostream>
using namespace std;
#include "node.h"

class LinkedList {
    Node* head = NULL;

    public:

    // insert the node at the end of the list
    void insertAtEnd(int);

    // print the list
    void printList();

    // finding the middle element in the list
    void middleElement();
};

// insert the node at the end of the list
void LinkedList::insertAtEnd(int data) {
    Node* newNode = new Node(data);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// finding the middle element in the list
void LinkedList::middleElement() {
    int middleValue, count = 0, itr = 1, middleIndex;

    if(head == NULL) {
        cout << "List is empty!" << endl;
    } else {

        Node* temp = head;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        if(count % 2 == 0) {
            middleIndex = 1 + (count - 1) / 2;
            middleIndex++;
        } else {
            middleIndex = 1 + (count - 1) / 2;
        }

        temp = head;
        while(itr < middleIndex) {
            temp = temp->next;
            itr++;
        }

        middleValue = temp->data;
        cout << "Middle value of the list is: " << middleValue << endl;
    }
}

// printing the list
void LinkedList::printList() {
    if(head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
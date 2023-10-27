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

    // reverse singly linked list
    void reverseSinglyList();

    // reverse doubly linked list
    void reverseDoublyList();
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

// Que: 1. Find the middle element in the singly linked list

// ************** BRUTE FORCE APPROACH ***************
// void LinkedList::middleElement() {
//     int middleValue, count = 0, itr = 1, middleIndex;

//     if(head == NULL) {
//         cout << "List is empty!" << endl;
//     } else {

//         Node* temp = head;
//         while(temp != NULL) {
//             count++;
//             temp = temp->next;
//         }

//         if(count % 2 == 0) {
//             middleIndex = 1 + (count - 1) / 2;
//             middleIndex++;
//         } else {
//             middleIndex = 1 + (count - 1) / 2;
//         }

//         temp = head;
//         while(itr < middleIndex) {
//             temp = temp->next;
//             itr++;
//         }

//         middleValue = temp->data;
//         cout << "Middle value of the list is: " << middleValue << endl;
//     }
// }

// Que: 1. Find the middle element in the singly linked list

// ************ OPTIMISED APPROACH *************
void LinkedList::middleElement() {
    int middleValue;
    Node* slow_ptr = head;
    Node* fast_ptr = head;

    if(head == NULL) {
        cout << "List is empty!" << endl;
    } else {
        while(fast_ptr != NULL && fast_ptr->next != NULL) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        middleValue = slow_ptr->data;
        cout << "Middle value in the list is: " << middleValue << endl;
    }
}

// Que: 2. Reverse the singly linked list
void LinkedList::reverseSinglyList() {
    Node* prev = head;
    Node* curr = head;
    Node* next = head;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head->next = NULL;
    head = prev;
}

// Que: 3. Reverse the doubly linked list
void LinkedList::reverseDoublyList() {
    
}

// printing the list
void LinkedList::printList() {
    if(head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    cout << endl;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
#include <iostream>
#include "doublyLinkedList.h"
using namespace std;

void DoublyLinkedList::insertAtPos(int data, int pos) {
    Node* newNode = new Node(data);

    if (pos == 1) {
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    if (head == NULL) {
        cout << "Cannot add new node at this position" << endl;
        return;
    }

    Node* temp = head;
    int nodeCounter = 1;

    while (nodeCounter < pos - 1 && temp != NULL) {
        temp = temp->next;
        nodeCounter++;
    }

    if (temp == NULL || pos < 1) {
        cout << "Cannot add new node at this position" << endl;
        exit(0);
    }

    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

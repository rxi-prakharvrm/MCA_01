#include <iostream>
#include "doublyLinkedList.h"

void DoublyLinkedList::insertAtEnd(int data) {
    Node* newNode = new Node(data);

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }
}

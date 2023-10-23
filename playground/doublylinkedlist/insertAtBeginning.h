#include <iostream>
#include "doublyLinkedList.h"

void DoublyLinkedList::insertAtBeginning(int data) {
    Node* newNode = new Node(data);
    
    if(head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

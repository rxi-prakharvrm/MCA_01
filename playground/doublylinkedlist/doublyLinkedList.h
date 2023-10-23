#include <iostream>
#include "node.h"

class DoublyLinkedList {
    Node* head;

    public:
    DoublyLinkedList() {
        head = NULL;
    }

    // add node at the end of the list
    void insertAtEnd(int);

    // add node at the beginning of the list
    void insertAtBeginning(int);

    // add node at the specific position in the list
    void insertAtPos(int, int);

    // delete node from the end of the list
    void deleteFromEnd();

    // delete node from the beginning of the list
    void deleteFromBeginning();

    // print the list
    void printList();
};
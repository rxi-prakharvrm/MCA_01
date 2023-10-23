#include <iostream>
#include "doublyLinkedList.h"

int main() {
    DoublyLinkedList DLL;

    // Adding the nodes at the endl of the doubly linked list
    DLL.insertAtEnd(1);
    // DLL.insertAtEnd(2);
    // DLL.insertAtEnd(3);

    // Adding the nodes at the beginning of the doubly linked list
    // DLL.insertAtBeginning(23);
    // DLL.insertAtBeginning(24);
    // DLL.insertAtBeginning(25);

    // Adding the nodes at the specific position of the doubly linked list
    // DLL.insertAtPos(50, 4);

    // Delete node from the end of the list
    // DLL.deleteFromEnd();

    // Delete node from the beginning of the list
    // DLL.deleteFromBeginning();
    // DLL.deleteFromBeginning();

    // Printing the list
    DLL.printList();
    return 0;
}
#include <iostream>
#include "doublyLinkedList.h"
using namespace std;

void DoublyLinkedList::printList() {
    if(head == NULL) {
        cout << "Empty List!" << endl;
        exit(0);
    }

    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

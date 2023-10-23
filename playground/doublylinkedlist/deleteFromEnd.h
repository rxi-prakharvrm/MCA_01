#include <iostream>
#include "doublyLinkedList.h"
using namespace std;

void DoublyLinkedList::deleteFromEnd() {
    if(head == NULL) {
        cout << "Empty list! Can't delete node" << endl;
        exit(0);
    }

    Node* temp = head;
    if(temp->next == NULL) {
        delete temp;
        head = NULL;
        return;
    }

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

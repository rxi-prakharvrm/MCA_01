#include <iostream>
#include "doublyLinkedList.h"
using namespace std;

void DoublyLinkedList::deleteFromBeginning() {
    if(head == NULL) {
        cout << "Can't delete, list is empty!" << endl;
        exit(0);
    }

    Node* temp = head;
    if(temp->next == NULL) {
        delete temp;
        head = NULL;
        return;
    }

    head = head->next;
    delete head->prev;
    head->prev = NULL;
}

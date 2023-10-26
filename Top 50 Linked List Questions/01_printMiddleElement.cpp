#include <iostream>
#include "linkedList.h"

using namespace std;

int main() {
    LinkedList LL;

    // insert the node in the list
    LL.insertAtEnd(1);
    LL.insertAtEnd(21);
    LL.insertAtEnd(30);
    LL.insertAtEnd(4);

    // getting the middleValue in the linked list
    LL.middleElement();

    // print the list
    // LL.printList();
    return 0;
}
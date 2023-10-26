#include <iostream>
#include "linkedList.h"

using namespace std;

int main() {
    LinkedList LL;

    // insert the node in the list
    LL.insertAtEnd(1);
    LL.insertAtEnd(2);
    LL.insertAtEnd(3);
    LL.insertAtEnd(4);
    LL.insertAtEnd(5);

    // getting the middleValue in the linked list
    // LL.middleElement();

    // reverse the list
    LL.reverseList();

    // print the list
    LL.printList();
    return 0;
}
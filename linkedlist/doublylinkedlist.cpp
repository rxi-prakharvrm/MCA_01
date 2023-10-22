#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

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

    // print the list
    void printList();
};

// Adding the data at the end of the list
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

// Adding the node at the beginning of the doubly linked list
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

// Adding the node at a specific position in the list
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
    int totalNodes = 1;

    while(temp->next != NULL) {
        temp = temp->next;
        totalNodes++;
    }

    temp = head;
    while (nodeCounter < pos - 1 && temp != NULL) {
        temp = temp->next;
        nodeCounter++;
    }

    if (temp == NULL || pos < 1 || pos > totalNodes + 1) {
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

// Printing the doubly linked list
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

int main() {
    DoublyLinkedList DLL;

    // Adding the nodes at the endl of the doubly linked list
    DLL.insertAtEnd(1);
    DLL.insertAtEnd(2);
    DLL.insertAtEnd(3);

    // Adding the nodes at the beginning of the doubly linked list
    DLL.insertAtBeginning(23);
    DLL.insertAtBeginning(24);
    DLL.insertAtBeginning(25);

    // Adding the nodes at the specific position of the doubly linked list
    DLL.insertAtPos(50, 5);

    // Printing the list
    DLL.printList();
    return 0;
}
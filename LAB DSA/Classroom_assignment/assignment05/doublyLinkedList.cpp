#include <iostream>
using namespace std;

// Node class
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

// Main class of double linked list that accumulates all the functions
class DoublyLinkedList {
    Node* head;

    public:
    DoublyLinkedList() {
        head = NULL;
    }

    // traverse forward
    void traverseForward();

    // traverse backward
    void traverseBackward();

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

    // deletion of the node for a given key
    void deleteForKey(int);
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

    while (nodeCounter < pos - 1 && temp != NULL) {
        temp = temp->next;
        nodeCounter++;
    }

    if (temp == NULL || pos < 1) {
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

// Deleting from the ene of the list
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

// Deleting node from the beginning of the list
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

// traversing forward in doubly linked list
void DoublyLinkedList::traverseForward() {
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

// traversing backward in doubly linked list
void DoublyLinkedList::traverseBackward() {
    if(head == NULL) {
        cout << "Empty List!" << endl;
        exit(0);
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    head = temp;
    temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

// Deletion of the node for a given key
void DoublyLinkedList::deleteForKey(int key) {
    Node *temp = head;
    while(temp->data != key) {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
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
    DLL.insertAtPos(50, 4);

    // Delete node from the end of the list
    DLL.deleteFromEnd();

    // Delete for a given key
    DLL.deleteForKey(50);

    // Delete node from the beginning of the list
    DLL.deleteFromBeginning();
    DLL.deleteFromBeginning();

    // traverse backward
    DLL.traverseForward();
    
    // traverse backward
    DLL.traverseBackward();
    return 0;
}
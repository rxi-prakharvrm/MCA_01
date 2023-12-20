#include <iostream>
using namespace std;

// Node class
template<class T>
class Node {
    public:
    Node(T e = T()) : data(e), prev(nullptr), next(nullptr) {}

    int data;
    Node* prev;
    Node* next;
};

// Main class of double linked list that accumulates all the functions
template<class T>
class DoublyLinkedList {
    Node<T>* head;

    public:
    DoublyLinkedList() : head(nullptr) {}

    // add node at the end of the list
    void insertAtEnd(T data);

    // add node at the beginning of the list
    void insertAtBeginning(T data);

    // add node at the specific position in the list
    void insertAtPos(T data, int pos);

    // delete node from the end of the list
    void deleteFromEnd();

    // delete node from the beginning of the list
    void deleteFromBeginning();

    // print the list
    void printList();
};

// Adding the data at the end of the list
template<class T>
void DoublyLinkedList<T>::insertAtEnd(T data) {
    Node<T>* newNode = new Node<T>(data);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Adding the node at the beginning of the doubly linked list
template<class T>
void DoublyLinkedList<T>::insertAtBeginning(T data) {
    Node<T>* newNode = new Node<T>(data);
    
    if(head == nullptr) {
        head = newNode;
    } else {
        Node<T>* temp = head;

        while(temp->next != nullptr) {
            temp = temp->next;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Adding the node at a specific position in the list
template<class T>
void DoublyLinkedList<T>::insertAtPos(T data, int pos) {
    Node<T>* newNode = new Node<T>(data);

    if (pos == 1) {
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    if (head == nullptr) {
        cout << "Cannot add new node at this position" << endl;
        return;
    }

    Node<T>* temp = head;
    int nodeCounter = 1;

    while (nodeCounter < pos - 1 && temp != nullptr) {
        temp = temp->next;
        nodeCounter++;
    }

    if (temp == nullptr || pos < 1) {
        cout << "Cannot add new node at this position" << endl;
        exit(0);
    }

    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;

    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }
}

// Deleting from the ene of the list
template<class T>
void DoublyLinkedList<T>::deleteFromEnd() {
    if(head == nullptr) {
        cout << "Empty list! Can't delete node" << endl;
        exit(0);
    }

    Node<T>* temp = head;
    if(temp->next == nullptr) {
        delete temp;
        head = nullptr;
        return;
    }

    while(temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

// Deleting node from the beginning of the list
template<class T>
void DoublyLinkedList<T>::deleteFromBeginning() {
    if(head == nullptr) {
        cout << "Can't delete, list is empty!" << endl;
        exit(0);
    }

    Node<T>* temp = head;
    if(temp->next == nullptr) {
        delete temp;
        head = nullptr;
        return;
    }

    head = head->next;
    delete head->prev;
    head->prev = nullptr;
}

// Printing the doubly linked list
template<class T>
void DoublyLinkedList<T>::printList() {
    if(head == nullptr) {
        cout << "Empty List!" << endl;
        exit(0);
    }

    Node<T>* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    DoublyLinkedList<int> DLL;

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

    // Delete node from the beginning of the list
    DLL.deleteFromBeginning();
    DLL.deleteFromBeginning();

    // Printing the list
    DLL.printList();
    return 0;
}
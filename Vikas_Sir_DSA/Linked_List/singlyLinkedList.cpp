#include <iostream>
using namespace std;

template<class T>
class Node {
public:
    Node(const T e) : data(e), next(nullptr) {}
    T data;
    Node* next;
};

template<class T>
class SinglyLinkedList {
    Node<T>* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtEnd(T data);
    void insertAtBeginning(T data);
    void insertAtPos(T data, int pos);
    void deleteFromEnd();
    void deleteFromBeginning();
    void deleteFromPos(int pos);
    void printList();
};

template<class T>
void SinglyLinkedList<T>::insertAtEnd(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node<T>* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

template<class T>
void SinglyLinkedList<T>::insertAtBeginning(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

template<class T>
void SinglyLinkedList<T>::insertAtPos(T data, int pos) {
    Node<T>* newNode = new Node<T>(data);
    Node<T>* temp = head;
    Node<T>* prev = nullptr;
    int counter = 1;
    while (temp != nullptr) {
        counter++;
        temp = temp->next;
    }
    temp = head;
    if (pos > counter || pos < 1) {
        cout << "Cannot add at position: " << pos << endl;
        exit(0);
    }
    while (--pos != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (pos == 0 && prev == nullptr) {
        newNode->next = head;
        head = newNode;
    }
    else if (prev == nullptr) {
        insertAtEnd(data);
    }
    else {
        newNode->next = temp;
        prev->next = newNode;
    }
}

template<class T>
void SinglyLinkedList<T>::deleteFromEnd() {
    if (head == nullptr) {
        cout << "No node to delete" << endl;
        return;
    }
    Node<T>* temp = head;
    if (temp->next == nullptr) {
        delete temp;
        head = nullptr;
        return;
    }
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

template<class T>
void SinglyLinkedList<T>::deleteFromBeginning() {
    if (head == nullptr) {
        cout << "No node to delete" << endl;
        return;
    }
    Node<T>* temp = head;
    head = temp->next;
    delete temp;
}
template<class T>
void SinglyLinkedList<T>::deleteFromPos(int pos) {
    Node<T>* temp = head;
    int countNode = 0;

    // If no node is there to delete
    if (temp == nullptr) {
        cout << "No node to delete" << endl;
        return; // Don't use exit(0) for non-fatal errors, just return.
    }

    // count the total number of nodes
    while (temp != nullptr) {
        temp = temp->next;
        countNode++;
    }

    // Check for an invalid position
    if (pos > countNode || pos < 1) {
        cout << "Invalid Position" << endl;
        return;
    }

    temp = head;
    if (pos == 1) {
        // temp = head;
        head = temp->next;
        delete temp;
        return;
    }

    Node<T>* prevNode = head;
    Node<T>* currNode = prevNode->next;

    while (pos > 2) {
        prevNode = currNode;
        currNode = currNode->next;
        pos--;
    }

    prevNode->next = currNode->next;
    delete currNode;
}


template<class T>
void SinglyLinkedList<T>::printList() {
    Node<T>* temp = head;
    if (head == nullptr) {
        cout << "Empty List!" << endl;
        return;
    }
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    SinglyLinkedList<int> LL;
    LL.insertAtEnd(1);
    LL.insertAtEnd(2);
    LL.insertAtEnd(3);
    LL.insertAtEnd(4);
    LL.insertAtBeginning(14);
    LL.insertAtPos(15, 5);
    LL.insertAtPos(23, 7);
    LL.deleteFromBeginning();
    LL.deleteFromPos(2);
    LL.printList();
    return 0;
}
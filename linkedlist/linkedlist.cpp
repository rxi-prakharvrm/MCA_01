#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist {
    Node* head;

    public:

    Linkedlist() { head = NULL; }

    // Inserting node at the end of the list
    void insertAtEnd(int);

    // Inserting node at the beginning of the list
    void insertAtBeginning(int);

    // Inserting node at the specific position
    void insertAtPos(int, int);

    // Deletion at the end of the list
    void deleteFromEnd();

    // Delete from beginning of the list
    void deleteFromBeginning();

    // Printing the list
    void printList();

    // void deleteNode(int);

};

void Linkedlist::insertAtEnd(int data) {
    // Create a Node
    Node* newNode = new Node(data);

    // Check if the list is empty or not
    // if empty then link the new node to the head
    // else link the new node to the last node
    if(head == NULL) {
        head = newNode;
        return;
    }

    // Traverse till end of list
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Inserting the node at the beginning of the list
void Linkedlist::insertAtBeginning(int data) {
    Node* newNode = new Node(data);

    if(head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

// Inserting the node at the specific position
void Linkedlist::insertAtPos(int data, int pos) {
    Node* newNode = new Node(data);
    Node* temp = head;
    Node* prev = NULL;
    int counter = 1;

    while(temp != NULL) {
        counter++;
        temp = temp->next;
    }

    temp = head;

    if(pos > counter || pos < 1) {
        cout << "Cannot add at position: " << pos << endl;
        exit(0);
    }

    // if(temp == NULL) {
    //     cout << "Can't add node at this position" << endl;
    //     return ;
    // }
    while(--pos!=0) {
        prev= temp;
        temp = temp->next;
    }
    if(pos==0 && prev==NULL){
        newNode->next = head;
        head =newNode;
    }
    else if(prev==NULL){
        insertAtEnd(data);
    }
    else{
        newNode->next = temp;
        prev->next = newNode;
    }
}

// Function to delete the node at the end of the list
void Linkedlist::deleteFromEnd() {
    Node* temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    // deleting the last node
    delete temp->next;

    temp->next = NULL;
}

// Deleting the node from the beginning of the list
void Linkedlist::deleteFromBeginning() {
    Node* temp = head;

    if(temp == NULL) {
        cout << "No node to delete" << endl;
    }

    temp = head;
    head = head->next;
    delete temp;
}

// Printing the list
void Linkedlist::printList() {
    Node* temp = head;

    if(head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }

    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
};

// driver code
int main() {
    Linkedlist LL;
    LL.insertAtEnd(1);
    LL.insertAtEnd(2);
    LL.insertAtEnd(3);
    LL.insertAtEnd(4);

    // LL.insertAtBeginning(14);

    // LL.insertAtPos(15, 5);
    // LL.insertAtPos(23, 7);

    // LL.deleteNode();

    LL.deleteFromBeginning();

    LL.printList();
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *prev;
    Node *next;
    
    Node(int data) {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class CircularDoublyLinkedList {
    Node *head = NULL;
    public:
    
    // check whether the list is empty or not
    bool isEmpty();
    
    // count total nodes in the list
    int countNodes();
    
    // traverse list
    void traverse();
    
    // insert node at the beginning of the list
    void insertAtBeginning();
    
    // delete from the end of the list
    void deleteFromEnd();
};

// function to check whether the list is empty or not
bool CircularDoublyLinkedList::isEmpty() {
    if(head == NULL) return true;
    else return false;
}

// functioin to count total nodes in the list
int CircularDoublyLinkedList::countNodes() {
    if(isEmpty()) return 0;
    Node *temp = head;
    int count = 1;
    while(temp->next != head) {
        temp = temp->next;
        count++;
    }
    return count;
}

// traverse list
void CircularDoublyLinkedList::traverse() {
    if (head == NULL) {
        cout << "List is empty!\n" << endl;
        return;
    }

    Node *temp = head->next;
    cout << head->data << "->";
    while(temp != head) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n" << endl;
}

// insert node at the beginning of the list
void CircularDoublyLinkedList::insertAtBeginning() {
    int value;
    cout << "Enter data you want to insert: ";
    cin >> value;
    
    Node *newNode = new Node(value);
    
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
    
    head = newNode;

    cout << "Node added successfully!" << endl << endl;
}

void CircularDoublyLinkedList::deleteFromEnd() {
    if(isEmpty()) {
        cout << "Nothing to delete!\n" << endl;
        return;
    }
    Node *temp = head->next;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->prev->next = head;
    delete temp;

    cout << "Node is deleted successfully!\n" << endl;
}

int main() {
    CircularDoublyLinkedList CDLL;
    bool isContinue = true;
    int choice;
    while(isContinue) {
        cout << "1. Check Whether the list is empty or not" << endl;
        cout << "2. Count Nodes" << endl;
        cout << "3. Traverse list" << endl;
        cout << "4. Insert node at the beginning" << endl;
        cout << "5. Delete node from the end of the list" << endl;
        cout << "6. Exit program" << endl;
        
        cout << endl << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
            (CDLL.isEmpty()) ? cout << "List is empty!\n" << endl : cout << "List isn't empty!\n" << endl;
            break;
            
            case 2:
            cout << "Total nodes: " << CDLL.countNodes() << endl << endl;
            break;
            
            case 3:
            CDLL.traverse();
            break;
            
            case 4:
            CDLL.insertAtBeginning();
            break;
            
            case 5:
            CDLL.deleteFromEnd();
            break;
            
            case 6:
            isContinue = false;
            break;
            
            default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
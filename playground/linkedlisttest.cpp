#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert node at the end of the list
void insertAtEnd(int data, Node* &head) {
    // insert at the end
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode; // Pass by ref. because of this change in real head node
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    if (head == NULL) {
        cout << "Empty list!" << endl;
        exit(0);
    }
    Node* temp = head;
    cout << endl;
    cout << head;
    while (temp != NULL) {
        cout << " -> [ " << temp->data << " | " << temp->next << " ]";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // create a head pointer of type Node
    Node* head = NULL;
    insertAtEnd(1, head);
    insertAtEnd(2, head);
    insertAtEnd(3, head);
    printList(head);
    return 0;
}
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
    void insertAtEnd();

    // add node at the specific position in the list
    void insertAfterKthPosition();

    // delete node from the end of the list
    void deleteFromEnd();

    // delete node from the beginning of the list
    void deleteFromBeginning();

    // deletion of the node for a given key
    void deleteForKey();
};

// Adding the data at the end of the list
void DoublyLinkedList::insertAtEnd() {
    int value;
    cout << "Enter the value that is to be inserted: ";
    cin >> value;
    Node* newNode = new Node(value);

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
    
    cout << "Data inserted successfully!" << endl << endl;
}

// Adding the node at a specific position in the list
void DoublyLinkedList::insertAfterKthPosition() {
    int value, k;
    cout << "Enter the position after which you want to insert the value: ";
    cin >> k;
    cout << "Enter the value that is to be inserted: ";
    cin >> value;
    
    Node* newNode = new Node(value);

    int totalNodes = 0;
    Node* temp = head;

    while (temp != NULL) {
        totalNodes++;
        temp = temp->next;
    }

    // Check if k is out of bounds
    if (k <= 0 || k > totalNodes) {
        cout << "Invalid position." << endl;
        return;
    }

    if (k == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    temp = head;
    int nodeCounter = 1;

    while (nodeCounter < k && temp != NULL) {
        temp = temp->next;
        nodeCounter++;
    }

    if (temp == NULL) {
        cout << "Invalid position." << endl;
        return;
    }

    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    
    cout << "Data inserted successfully!" << endl << endl;
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
    
    cout << "Data deleted successfully!" << endl << endl;
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
    
    cout << "Data deleted successfully!" << endl << endl;
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
    cout << "NULL\n" << endl;
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

    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << "NULL\n" << endl;
}

// Deletion of the node for a given key
void DoublyLinkedList::deleteForKey() {
    int key;
    cout << "Enter the key you want to delete from the list: ";
    cin >> key;
    Node *temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Key not found in the list\n" << endl;
        return;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    delete temp;

    cout << "Data deleted successfully!" << endl << endl;
}


int main() {
    DoublyLinkedList DLL;
    int choice = 0;
    bool isContinue = true;
    while(isContinue) {
        cout << "1. Insert node at the end" << endl;
        cout << "2. Insert node after kth position" << endl;
        cout << "3. Delete node from the beginning" << endl;
        cout << "4. Delete node from the end" << endl;
        cout << "5. Delete node for a key" << endl;
        cout << "6. Traverse forward" << endl;
        cout << "7. Traverse backward" << endl;
        cout << "8. Exit program" << endl;
        
        cout << endl << "Enter one choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                DLL.insertAtEnd();
                break;
            case 2:
                DLL.insertAfterKthPosition();
                break;
            case 3:
                DLL.deleteFromBeginning();
                break;
            case 4:
                DLL.deleteFromEnd();
                break;
            case 5:
                DLL.deleteForKey();
                break;
            case 6:
                DLL.traverseForward();
                break;
            case 7:
                DLL.traverseBackward();
                break;
            case 8:
                isContinue = false;
                break;
            default:
                cout << "Invalid choice, select again!" << endl << endl;
        }
    }
    return 0;
}
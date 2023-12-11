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

class SinglyLinkedList {
    Node* head;

    public:

    SinglyLinkedList() { head = NULL; }

    // Inserting node at the end of the list
    void insertAtEnd();

    // Inserting node at the beginning of the list
    void insertAtBeginning();

    // Inserting node at the specific position
    void insertAtPos();

    // Deletion at the end of the list
    void deleteFromEnd();

    // Delete from beginning of the list
    void deleteFromBeginning();

    // Delete from a specific position in the list
    void deleteFromPos();
    
    // Sort list
    void sortList();
    
    // Reverse list
    void reverseList();

    // Printing the list
    void printList();
};

void SinglyLinkedList::insertAtEnd() {
    // Prompt user to input value
    int value;
    cout << "Enter value you want to insert end: ";
    cin >> value;

    // Create a Node
    Node* newNode = new Node(value);

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
void SinglyLinkedList::insertAtBeginning() {
    // Prompt user to input some value
    int value;
    cout << "Enter value you want to insert at beginning: ";
    cin >> value;

    Node* newNode = new Node(value);

    if(head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

// Inserting the node at the specific position
void SinglyLinkedList::insertAtPos() {
    int count = 2, value, pos, totalNodes = 0;
    Node *prev = head;
    Node *curr = head;

    cout << "Enter the position where is to be inserted: ";
    cin >> pos;

    cout << "Enter the value that is to be inserted at position " << pos << ": ";
    cin >> value;

    Node *newNode = new Node(value);

    // count total nodes
    Node *temp = head;
    while(temp != NULL) {
        totalNodes++;
        temp = temp->next;
    }

    if(pos!=1 && pos > totalNodes) {
        cout<<"Size of your linked list is "<<totalNodes<<" and u wanna insert at position = "<<pos<<endl;
        return;
    }

    if(pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        int start = 1;
        int destination=pos;
        while(start<destination-1) {
            curr = curr->next;
            start++;
        }
        // curr->next = newNode
        newNode->next = curr->next;
        curr->next= newNode;
    }
}

// Function to delete the node at the end of the list
void SinglyLinkedList::deleteFromEnd() {
    Node* temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    // deleting the last node
    delete temp->next;

    temp->next = NULL;
}

// Deleting the node from the beginning of the list
void SinglyLinkedList::deleteFromBeginning() {
    Node* temp = head;

    if(head == NULL) {
        cout << "No node to delete" << endl;
    }

    temp = head;
    head = temp->next;
    delete temp;
}

// Delete node from the specific position from the list
void SinglyLinkedList::deleteFromPos() {
    // Prompt the user to enter the position from where the value should be deleted
    int pos;
    cout << "Enter the position from where you want to delete value: ";
    cin >> pos;

    Node* temp = head;
    if(pos == 1) {
        head = head->next;
        delete temp;
        return;
    }

    Node* prevNode = head;
    Node* currNode = prevNode->next;
    int counter = 2;
    int countNode = 1;

    while(temp->next != NULL) {
        temp = temp->next;
        countNode++;
    }

    if(head == NULL || pos < 1 || pos > countNode) {
        cout << "Can't delete from this position" << endl;
        exit(0);
    }

    while(counter < pos) {
        prevNode = prevNode->next;
        currNode = prevNode->next;
        counter++;
    }

    prevNode->next = currNode->next;
    delete currNode;
}

// Sort list
void SinglyLinkedList::sortList() {
    Node *prev = head;
    Node *curr = prev->next;
    
    int totalNodes = 0;
    Node * temp = head;
    
    while(temp != NULL) {
        totalNodes++;
        temp = temp->next;
    }
    
    while(totalNodes >= 0) {
        while(curr != NULL) {
            if(prev->data > curr->data) {
                swap(prev->data, curr->data);
            }
            prev = prev->next;
            curr = curr->next;
        }
        prev = head;
        curr = prev->next;
        totalNodes--;
    }
}

// Reverse the list
void SinglyLinkedList::reverseList() {
    Node *prev = NULL;
    Node *curr = head;

    while(curr != NULL) {
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

// Printing the list
void SinglyLinkedList::printList() {
    Node* temp = head;

    if(head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }

    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl << endl;
};

// driver code
int main() {
    SinglyLinkedList LL;
    int choice = 0;
    bool isContinue = true;
    while(isContinue) {
        cout << "1. Insert node at the beginning" << endl;
        cout << "2. Insert node at the end" << endl;
        cout << "3. Insert node at the specific position" << endl;
        cout << "4. Delete node from the beginning" << endl;
        cout << "5. Delete node from the end" << endl;
        cout << "6. Delete node from the specific position" << endl;
        cout << "7. Sort the list" << endl;
        cout << "8. Reverse the list" << endl;
        cout << "9. Print the list" << endl;
        cout << "10. Exit program" << endl;
        
        cout << endl << "Enter one choice: ";
        cin >> choice;
        
        int value, pos;

        switch(choice) {
            case 1:
                LL.insertAtBeginning();
                cout << "Data inserted successfully!" << endl << endl;
                break;
            case 2:
                LL.insertAtEnd();
                cout << "Data inserted successfully!" << endl << endl;
                break;
            case 3:
                LL.insertAtPos();
                break;
            case 4:
                LL.deleteFromBeginning();
                cout << "Data deleted successfully!" << endl << endl;
                break;
            case 5:
                LL.deleteFromEnd();
                cout << "Data deleted successfully!" << endl << endl;
                break;
            case 6:
                LL.deleteFromPos();
                cout << "Data deleted successfully!" << endl << endl;
                break;
            case 7:
                LL.sortList();
                cout << "Data sorted successfully!" << endl << endl;
                break;
            case 8:
                LL.reverseList();
                cout << "List reversed successfully!" << endl << endl;
                break;
            case 9:
                LL.printList();
                break;
            case 10:
                isContinue = false;
                break;
            default:
                cout << "Invalid choice, select again!" << endl << endl;
        }
    }
    return 0;
}
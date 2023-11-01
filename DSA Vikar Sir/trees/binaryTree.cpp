#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree {
    Node* root;
    public:

    Tree() : root(NULL) {}

    void addLeftNode(int item) {
        Node* leftNode = new Node(item);
        if(root == NULL) {
            root = leftNode;
        } else {
            Node* temp = root;
            while(temp->left != NULL) {
                temp = temp->left;
            }
            temp->left = leftNode;
        }
    }

    void addRightNode(int item) {
        Node* rightNode = new Node(item);
        if(root == NULL) {
            root = rightNode;
        } else {
            Node* temp = root;
            while(temp->right != NULL) {
                temp = temp->right;
            }
            temp->right = rightNode;
        }
    }

    void preOrderTraversal() {
        if(root == NULL) {
            cout << "Empty Tree!" << endl;
            return;
        } else {
            Node* temp = root;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->left;
            }
        }
    }
};

int main() {
    Tree t;
    t.addLeftNode(1);
    t.addLeftNode(2);
    t.addLeftNode(4);
    t.addRightNode(5);
    t.addRightNode(3);
    t.addLeftNode(6);
    t.addRightNode(7);
    
    return 0;
}
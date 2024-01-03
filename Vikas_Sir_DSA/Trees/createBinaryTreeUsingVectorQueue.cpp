#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in the binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node with given data
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to create a binary tree using level order traversal
void create(Node *&root) {
    Node *p, *t;
    int x;
    queue<Node*> q;

    // Input root value
    cout << "Enter root value: ";
    cin >> x;
    root = new Node(x);
    q.push(root);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        // Input left child
        cout << "Enter left child: ";
        cin >> x;
        if (x != -1) {
            t = new Node(x);
            p->left = t;
            q.push(t);
        }

        // Input right child
        cout << "Enter right child: ";
        cin >> x;
        if (x != -1) {
            t = new Node(x);
            p->right = t;
            q.push(t);
        }
    }
}

// Pre-order traversal of the binary tree
void preOrderTraversal(Node *p) {
    if (p != NULL) {
        cout << p->data << " ";
        preOrderTraversal(p->left);
        preOrderTraversal(p->right);
    }
}

// In-order traversal of the binary tree
void inOrderTraversal(Node *p) {
    if (p != NULL) {
        inOrderTraversal(p->left);
        cout << p->data << " ";
        inOrderTraversal(p->right);
    }
}

// Post-order traversal of the binary tree
void postOrderTraversal(Node *p) {
    if (p != NULL) {
        postOrderTraversal(p->left);
        postOrderTraversal(p->right);
        cout << p->data << " ";
    }
}

// Function to count the total number of nodes in the binary tree
int countNodes(Node *p) {
    if (p != NULL)
        return countNodes(p->left) + countNodes(p->right) + 1;
    return 0;
}

// Function to count nodes having two children in the binary tree
int countTwoChildrenNodes(Node *p) {
    if (p == NULL)
        return 0;
    if (p->left != NULL && p->right != NULL)
        return countTwoChildrenNodes(p->left) + countTwoChildrenNodes(p->right) + 1;
    else
        return countTwoChildrenNodes(p->left) + countTwoChildrenNodes(p->right);
}

// Function to count internal nodes in the binary tree
int countInternalNodes(Node *p) {
    if (p == NULL)
        return 0;
    if (p->left != NULL || p->right != NULL)
        return countInternalNodes(p->left) + countInternalNodes(p->right) + 1;
    else
        return countInternalNodes(p->left) + countInternalNodes(p->right);
}

// Function to count external nodes (leaves) in the binary tree
int countExternalNodes(Node *p) {
    if (p == NULL)
        return 0;
    if (p->left == NULL && p->right == NULL)
        return countExternalNodes(p->left) + countExternalNodes(p->right) + 1;
    else
        return countExternalNodes(p->left) + countExternalNodes(p->right);
}

// Function to calculate the height of the binary tree
int heightOfTree(Node *p) {
    int x, y;
    if (p != NULL) {
        x = heightOfTree(p->left);
        y = heightOfTree(p->right);
        return (x > y) ? x + 1 : y + 1;
    }
    return 0;
}

// Function to interchange the left and right subtrees of each node in the binary tree
void interchangeSubtrees(Node* &p) {
    if (p != NULL) {
        Node *temp = p->left;
        p->left = p->right;
        p->right = temp;
        interchangeSubtrees(p->left);
        interchangeSubtrees(p->right);
    }
}

// Main function
int main() {
    Node *root;
    create(root);

    cout << endl;

    cout << "Pre: "; preOrderTraversal(root); cout << endl;
    cout << "In: "; inOrderTraversal(root); cout << endl;
    cout << "Post: "; postOrderTraversal(root); cout << endl;

    cout << endl;

    cout << "Total number of nodes: " << countNodes(root) << endl;
    cout << "Nodes having two children are: " << countTwoChildrenNodes(root) << endl;
    cout << "Internal nodes: " << countInternalNodes(root) << endl;
    cout << "External nodes: " << countExternalNodes(root) << endl;

    cout << endl;

    cout << "Height of the tree is: " << heightOfTree(root) << endl;

    cout << endl;

    // Interchange subtrees
    interchangeSubtrees(root);
    cout << "Traversals after interchanging subtrees ------" << endl;

    cout << endl;

    cout << "Pre: "; preOrderTraversal(root); cout << endl;
    cout << "In: "; inOrderTraversal(root); cout << endl;
    cout << "Post: "; postOrderTraversal(root); cout << endl;

    return 0;
}

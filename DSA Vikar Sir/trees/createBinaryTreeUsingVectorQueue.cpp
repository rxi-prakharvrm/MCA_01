#include <iostream>
#include <bits/stdc++.h>
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

void create(Node *&root) {
    Node *p, *t;
    int x;
    queue<Node*> q;
    cout << "Enter root value: ";
    cin >> x;
    root = new Node(x);
    q.push(root);
    while(!q.empty()) {
        p = q.front();
        q.pop();
        cout << "Enter left child: ";
        cin >> x;
        if(x != -1) {
            t = new Node(x);
            p->left = t;
            q.push(t);
        }
        cout << "Enter right child: ";
        cin >> x;
        if(x != -1) {
            t = new Node(x);
            p->right = t;
            q.push(t);
        }
    }
}

void preOrderTraversal(Node *p) {
    if(p != NULL) {
        cout << p->data << " ";
        preOrderTraversal(p->left);
        preOrderTraversal(p->right);
    }
}

void inOrderTraversal(Node *p) {
    if(p != NULL) {
        inOrderTraversal(p->left);
        cout << p->data << " ";
        inOrderTraversal(p->right);
    }
}

void postOrderTraversal(Node *p) {
    if(p != NULL) {
        postOrderTraversal(p->left);
        postOrderTraversal(p->right);
        cout << p->data << " ";
    }
}

int countNodes(Node *p) {
    if(p != NULL)
        return countNodes(p->left) + countNodes(p->right) + 1;
    return 0;
}

int countTwoChildrenNodes(Node *p) {
    if(p == NULL)
        return 0;
    if(p->left != NULL && p->right != NULL)
        return countTwoChildrenNodes(p->left) + countTwoChildrenNodes(p->right) + 1;
    else
        return countTwoChildrenNodes(p->left) + countTwoChildrenNodes(p->right);
}

int countInternalNodes(Node *p) {
    if(p == NULL)
        return 0;
    if(p->left != NULL || p->right != NULL)
        return countInternalNodes(p->left) + countInternalNodes(p->right) + 1;
    else
        return countInternalNodes(p->left) + countInternalNodes(p->right);
}

int countExternalNodes(Node *p) {
    if(p == NULL)
        return 0;
    if(p->left == NULL && p->right == NULL)
        return countExternalNodes(p->left) + countExternalNodes(p->right) + 1;
    else
        return countExternalNodes(p->left) + countExternalNodes(p->right);
}

int heightOfTree(Node *p) {
    int x, y;
    if(p != NULL) {
        x = heightOfTree(p->left);
        y = heightOfTree(p->right);
        return (x > y) ? x+1 : y+1;
    }
    return 0;
}

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

    return 0;
}
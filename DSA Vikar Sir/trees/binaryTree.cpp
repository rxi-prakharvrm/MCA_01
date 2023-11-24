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

Node *root;

void create() {
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

int main() {
    create();

    cout << endl;
    cout << "Pre: "; preOrderTraversal(root); cout << endl;
    cout << "In: "; inOrderTraversal(root); cout << endl;
    cout << "Post: "; postOrderTraversal(root); cout << endl;

    return 0;
}
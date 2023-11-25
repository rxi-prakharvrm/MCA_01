#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void create(Node *&root) {
    Node *p, *t;
    int data;
    queue<Node *> q;
    cout << "Enter root value: ";
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        p = q.front();
        q.pop();
        cout << "Enter left child value: ";
        cin >> data;
        if(data != -1) {
            t = new Node(data);
            p->left = t;
            q.push(t);
        }
        cout << "Enter right child: ";
        cin >> data;
        if(data != -1) {
            t = new Node(data);
            p->right = t;
            q.push(t);
        }
    }
}

void printNodesAtKDistance(Node *root, int k) {
    if(root == NULL || k < 0)
        return;
    if(k == 0) {
        cout << root->data << " ";
        return;
    }
    printNodesAtKDistance(root->left, k-1);
    printNodesAtKDistance(root->right, k-1);
}

int main() {
    Node *root;
    create(root);

    cout << endl;

    int k = 3;
    cout << "Nodes at distance " << k << " are: ";
    printNodesAtKDistance(root, k);

    cout << endl;

    return 0;
}
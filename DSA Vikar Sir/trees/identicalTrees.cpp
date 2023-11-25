#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int item) : data(item), left(NULL), right(NULL) {}
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

bool identicalTrees(Node *root1, Node *root2) {
    if(root1 == NULL && root2 == NULL)
        return 1;
    if(root1 != NULL && root2 != NULL) {
        return (root1->data == root2->data && 
        root1->left->data == root2->left->data && 
        root1->right->data == root2->right->data);
    }
    return 0;
}

int main() {
    Node *root1;
    Node *root2;
    create(root1);
    create(root2);
    (identicalTrees(root1, root2)) ? cout << "Trees are identical" << endl : cout << "Trees are not identical" << endl;
    return 0;
}
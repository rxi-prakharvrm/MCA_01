#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int item) : data(item), left(NULL), right(NULL) {}
};

class Solution {
    public:
    void create(Node *&root) {
        Node *currentNode, *newNode;
        int x;
        queue<Node *> q;

        cout << "Enter root value: ";
        cin >> x;

        root = (Node *) malloc(sizeof(Node));
        root->data = x;
        root->left = NULL;
        root->right = NULL;

        q.push(root);

        while(!q.empty()) {
            currentNode = q.front();
            q.pop();

            cout << "Enter left child: ";
            cin >> x;

            if(x != -1) {
                newNode = (Node *) malloc(sizeof(Node));
                newNode->data = x;
                newNode->left = NULL;
                newNode->right = NULL;
                currentNode->left = newNode;
                q.push(newNode);
            }

            cout << "Enter right child: ";
            cin >> x;

            if(x != -1) {
                newNode = (Node *) malloc(sizeof(Node));
                newNode->data = x;
                newNode->left = NULL;
                newNode->right = NULL;
                currentNode->right = newNode;
                q.push(newNode);
            }
        }

    }

    void preOrder(Node *&root) {
        if(root == NULL) return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node *&root) {
        if(root == NULL) return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void postOrder(Node *&root) {
        if(root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    int countNodes(Node *root) {
        return (root != NULL) ? countNodes(root->left) + countNodes(root->right) + 1 : 0;
    }

    int countNodesHavingTwoChildren(Node *root) {
        int x, y;
        if(root != NULL) {
            x = countNodesHavingTwoChildren(root->left);
            y = countNodesHavingTwoChildren(root->right);

            return (root->left and root->right) ? x+y+1 : x+y;
        }
        return 0;
    }

    int countNodesHavingOneChild(Node *root) {
        int x, y;
        if(root != NULL) {
            x = countNodesHavingOneChild(root->left);
            y = countNodesHavingOneChild(root->right);

            return (!root->left ^ !root->right) ? x+y+1 : x+y;
        }
        return 0;
    }

    int countNodesHavingNoChild(Node *root) {
        int x, y;
        if(root != NULL) {
            x = countNodesHavingNoChild(root->left);
            y = countNodesHavingNoChild(root->right);

            return (!root->left and !root->right) ? x+y+1 : x+y;
        }
        return 0;
    }

    int sumOfNodes(Node *root) {
        return (root != NULL) ? sumOfNodes(root->left) + sumOfNodes(root->right) + root->data : 0;
    }

    int numberOfLevels(Node *root) {
        int x, y;
        if(root != NULL) {
            x = numberOfLevels(root->left);
            y = numberOfLevels(root->right);
            return (x > y) ? x+1 : y+1;
        }
        return 0;
    }
};

int main() {
    Node *root;
    Solution s;
    s.create(root);

    cout << endl;
    cout << "preOrder: "; s.preOrder(root);
    cout << endl;
    cout << "inOrder: "; s.inOrder(root);
    cout << endl;
    cout << "postOrder: "; s.postOrder(root);
    cout << endl;

    cout << endl << "Total number of nodes: " << s.countNodes(root) << endl;
    cout << endl << "Total nodes having two children: " << s.countNodesHavingTwoChildren(root) << endl;
    cout << endl << "Total nodes having one children: " << s.countNodesHavingOneChild(root) << endl;
    cout << endl << "Total nodes having zero children: " << s.countNodesHavingNoChild(root) << endl;
    cout << endl << "Sum of nodes: " << s.sumOfNodes(root) << endl;
    cout << endl << "Number of levels in the tree: " << s.numberOfLevels(root) << endl;
    return 0;
}
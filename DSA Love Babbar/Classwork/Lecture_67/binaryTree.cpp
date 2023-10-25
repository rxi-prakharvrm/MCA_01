#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root) {
    cout << "Enter the data: ";
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter the data to insert on the left: " << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data to insert on the right: " << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node *> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if(temp->left != NULL) {
            q.push(temp->left);
        }

        if(temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

int main() {
    Node* root = NULL;

    root = buildTree(root);

    // level order traversal or breadth first traversal
    levelOrderTraversal(root);

    return 0;
}
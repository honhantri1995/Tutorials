#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left, * right;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printInorder(struct Node* node) {
    if (node == NULL) {
        return;
    }

    // First recur on left child
    printInorder(node->left);

    // Then print the data of node
    cout << node->data << " ";

    // Now recur on right child
    printInorder(node->right);
}

// Driver code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Function call
    cout << "Inorder traversal of binary tree is \n";
    printInorder(root);

    return 0;
}

// binary tree traversal
// PREORDER POSTORDER INORDER

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* bst, int data)
{
    if (bst == NULL) {
        Node* temp = new Node(data);
        bst = temp; // insert the node to the NULL position
    } else if (data <= bst->data) {
        bst->left = insert(bst->left, data); // returns the address of the inserted node to the bst->left
    } else {
        bst->right = insert(bst->right, data); // returns the address of the inserted node to the bst->right
    }

    return bst; // returns the pointer to the previous recursive call
}
void inorderTraversal(Node* bst)
{
    // inorder prints the tree in a sorted way
    // LEFT->DATA->RIGHT LDR
    if (bst == NULL) {
        return;
    }

    inorderTraversal(bst->left);
    cout << bst->data << " ";
    inorderTraversal(bst->right);
}

void preorderTraversal(Node* bst)
{
    // prints DATA->LEFT->RIGHT DLR
    if (bst == NULL) {
        return;
    }

    cout << bst->data << " ";
    preorderTraversal(bst->left);
    preorderTraversal(bst->right);
}

void postorderTraversal(Node* bst)
{
    // prints LEFT->RIGHT->DATA  LRD
    if (bst == NULL) {
        return;
    }

    postorderTraversal(bst->left);
    postorderTraversal(bst->right);
    cout << bst->data << " ";
}

int main()
{
    Node* root = NULL;
    int n, data;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> data;
        root = insert(root, data);
    }

    inorderTraversal(root);
    cout << endl;
    preorderTraversal(root);
    cout << endl;
    postorderTraversal(root);
}

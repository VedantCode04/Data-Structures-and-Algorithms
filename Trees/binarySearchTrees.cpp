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

bool search(Node* bst, int n)
{
    if (bst == NULL)
        return false;
    else if (n == bst->data)
        return true;
    else if (n <= bst->data)
        return search(bst->left, n);
    else
        return search(bst->right, n);
}

int minElement(Node* bst)
{
    while (bst->left != NULL) {
        bst = bst->left;
    }

    return bst->data;
}

int maxElement(Node* bst)
{
    if (bst == NULL) {
        cout << "Is empty";
        return -1;
    }
    while (bst->right != NULL) {
        bst = bst->right;
    }

    return bst->data;
}

int height(Node* bst)
{
    if (bst == NULL) {
        return 0;
    }

    int leftTree = height(bst->left);
    int rightTree = height(bst->right);

    return 1 + max(leftTree, rightTree); // returns the max from leftTree and rightTree and adds 1 to the final answer and the height of the root is also added
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
    cout << search(root, 260) << endl; // returns a BOOL value
    cout << maxElement(root) << endl;
    cout << minElement(root) << endl;
    cout << height(root) << endl;
}

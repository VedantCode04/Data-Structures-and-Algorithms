// binary tree traversal
// Level Order Traversal

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

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;

    if (root == NULL) {
        return;
    }

    q.push(root); // pushes the root node into the queue

    while (!q.empty()) {
        Node* temp = q.front(); // stores the FRONT value of queue in the temp var
        cout << temp->data << " ";

        // pops the front value and then checks if the left and right nodes are present
        q.pop();

        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
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

    levelOrderTraversal(root);
}

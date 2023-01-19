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

void inorder(Node* bst)
{ // LNR
    if (bst == NULL)
        return;

    stack<Node*> tree;

    while (!tree.empty() || bst != NULL) {
        if (bst != NULL) {
            tree.push(bst);
            bst = bst->left;
        } else {
            Node* temp = tree.top(); // assigns the top Node* to temp node
            tree.pop();

            cout << temp->data << " ";
            bst = temp->right; // as BST is null, we assign the value of temp->right to bst and then continue the loop until the stack is empty and bst is NULL
        }
    }

    cout << endl;
}

void preorder(Node* bst)
{ // NLR
    if (bst == NULL)
        return;

    stack<Node*> tree;

    while (!tree.empty() || bst != NULL) {
        if (bst != NULL) {
            cout << bst->data << " ";
            tree.push(bst);
            bst = bst->left;
        } else {
            Node* temp = tree.top();
            tree.pop();
            bst = temp->right;
        }
    }

    cout << endl;
}

void postorder(Node* bst)
{ // LRN
    // using 2 stacks
    if (bst == NULL)
        return;

    stack<Node*> tree1;
    stack<Node*> tree2;
    tree1.push(bst);
    while (!tree1.empty()) {
        Node* temp = tree1.top();
        tree1.pop();

        tree2.push(temp);

        if (temp->left != NULL) {
            tree1.push(temp->left);
        }

        if (temp->right != NULL) {
            tree1.push(temp->right);
        }
    }

    while (!tree2.empty()) {
        cout << tree2.top()->data << " ";
        tree2.pop();
    }

    cout << endl;
}

void postorder2(Node* bst)
{
    // using 1 stack
    Node* root = bst;
    if (bst == NULL)
        return;

    stack<Node*> tree;
    vector<int> postOrder;
    while (!tree.empty() || bst != NULL) {
        if (bst != NULL) {
            tree.push(bst);
            bst = bst->left;
        } else {
            Node* temp = tree.top()->right;

            if (temp == NULL) {
                temp = tree.top();
                tree.pop();
                postOrder.emplace_back(temp->data); // store the values in vector and then print the vector , it will be in postorder form

                while (!tree.empty() && temp == tree.top()->right) {
                    temp = tree.top();
                    tree.pop();
                    postOrder.emplace_back(temp->data);
                }
            } else {
                bst = temp;
            }
        }
    }

    for (auto v : postOrder) {
        cout << v << " ";
    }
}

int main()
{
    Node* root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    inorder(root);

    preorder(root);

    postorder(root);

    postorder2(root);
}

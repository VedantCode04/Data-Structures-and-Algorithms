#include <bits/stdc++.h>
using namespace std;

class Bst {
public:
    int data;
    Bst* left;
    Bst* right;

    Bst(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Bst* makeNode(Bst* root, int data)
{
    Bst* temp = new Bst(data);
    return temp;
}

Bst* insert(Bst* root, int data)
{
    if (root == NULL) {
        return makeNode(root, data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

int height(Bst* root){
	if (root == NULL)
	{
		return 0;
	}

	int lheight = height(root->left);
	int rheight = height(root->right);

	return max(lheight, rheight) + 1;
}

int diameter(Bst* root){
	if (root == NULL) return 0;

	int ldiameter = diameter(root->left);
	int rdiameter = diameter(root->right);

	int lheight = height(root->left);
	int rheight = height(root->right);

	int diameter;

	diameter = max(lheight+rheight+1, max(ldiameter, rdiameter));

	return diameter;
}

void inorder(Bst* root){
	if (root == NULL)
	{
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main()
{
    Bst* root = NULL;

    for (int i = 0; i < 8; ++i) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    cout << diameter(root);
}

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) // constructor to initialise the Node
    {
        data = d;
        next = NULL;
    }
};

void print(Node* head)
{
    while (head != NULL) {
        cout << head->data << endl;
        head = head->next;
    }
}

int main()
{
    Node* head = new Node(10);
    Node* one = new Node(20);
    Node* two = new Node(30);
    Node* three = new Node(40);
    Node* tail = new Node(50);

    head->next = one;
    one->next = two;
    two->next = three;
    three->next = tail;

    print(head);
}

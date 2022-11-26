#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node* head = NULL;
Node* tail = NULL;

void insertEnd(int n)
{
    cout << "Enter data: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        Node* temp = new Node(data);

        if (head == NULL) {
            head = tail = temp;
            tail->next = head;
        } else {
            temp->next = head;
            tail->next = temp;
            tail = temp;
        }
    }
}

void print(Node* list)
{
    cout << "List is: ";
    while (list != tail) {
        cout << list->data << " ";
        list = list->next;
        if (list == tail) {
            cout << list->data;
        }
    }

    cout << "\n";
}
int main()
{

    int n;
    cout << "Enter total nodes to be inserted at end: ";
    cin >> n;
    insertEnd(n);
    print(head);
}

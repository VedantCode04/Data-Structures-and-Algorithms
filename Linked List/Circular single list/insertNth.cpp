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

void insert(int n)
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

void insertNth(int data, int pos)
{
    Node* temp = new Node(data);
    Node* ptr = head;
    if (pos == 1) {
        temp->next = head;
        head = temp;
        return;
    }

    for (int i = 1; i < pos - 1; ++i) {
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;
    return;
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

    int n, data, pos;
    cout << "Enter total nodes to be inserted: ";
    cin >> n;
    insert(n);

    cout << "Enter node to be inserted: ";
    cin >> data;
    cout << "Enter pos to be inserted: ";
    cin >> pos;
    insertNth(data, pos);
    print(head);
}

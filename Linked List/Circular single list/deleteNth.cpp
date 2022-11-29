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

void deleteFirst()
{
    Node* ptr = head;
    head = head->next;
    free(ptr);
    ptr = NULL;
}

void deleteNth(int pos)
{
    Node* current = head;
    Node* prev = NULL;

    if (pos == 1) {
        deleteFirst();
        return;
    }

    for (int i = 0; i < pos - 1; ++i) {
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    if (current == tail) {
        tail = prev;
    }
    free(current);
    current = NULL;
}

int main()
{

    int n, data, pos;
    cout << "Enter total nodes to be inserted: ";
    cin >> n;
    insert(n);
    print(head);

    cout << "Enter position:";
    cin >> pos;
    deleteNth(pos);
    cout << "After deleting: ";
    print(head);
}

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int data)
    {
        this->data = data;
        prev = next = NULL;
    }
};
Node* head;
Node* tail;

void print(Node* list)
{
    do {
        cout << list->data << " ";
        list = list->next;
    } while (list != head);

    cout << endl;
}

void insert(int data)
{
    Node* temp = new Node(data);

    if (head == NULL) {
        head = tail = temp;
        tail->next = head;
        head->prev = tail;
    } else {
        temp->next = head;
        temp->prev = tail;
        head = temp;
        tail->next = head;
    }
}

void insertBeg(int n)
{
    cout << "Enter data: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        insert(data);
    }
}

int main()
{
    cout << "Enter nodes to be inserted: ";
    int n;
    cin >> n;

    insertBeg(n);
    print(head);
}

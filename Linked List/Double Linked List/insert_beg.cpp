#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

void print(Node* list)
{
    while (list != NULL) {
        cout << list->data << " ";
        list = list->next;
    }

    cout << endl;
}

void insertStart(Node*& head, int data)
{
    Node* temp = new Node(data);
    temp->data = data;

    if (head == NULL) {
        head = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void newList(Node*& head, int n)
{

    cout << "enter data: ";

    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        insertStart(head, data);
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;
    int n;
    cout << "enter nodes to be inserted: ";
    cin >> n;

    newList(head, n);

    cout << "Final list is: ";
    print(head);
}

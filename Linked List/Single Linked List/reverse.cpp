#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
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

void insert(Node*& head, int n)
{
    cout << "enter data: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;

        Node* temp = new Node(data);

        if (head == NULL) {
            head = temp;
        } else {
            Node* ptr = head;

            while (ptr->next != NULL) {
                ptr = ptr->next;
            }

            ptr->next = temp;
        }
    }
}

void reverse(Node*& head)
{
    Node *ptr, *ptr2;
    ptr = NULL;
    ptr2 = NULL;

    while (head != NULL) {
        ptr2 = head->next;
        head->next = ptr;
        ptr = head;
        head = ptr2;
    }

    head = ptr;
}

int main()
{
    Node* head = NULL;
    int n;
    cout << "enter total nodes to be inserted: ";
    cin >> n;

    insert(head, n);

    reverse(head);

    cout << "after reverse: ";
    print(head);
}

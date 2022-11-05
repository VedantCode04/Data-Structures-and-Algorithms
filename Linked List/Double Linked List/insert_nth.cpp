#include <iostream>
using namespace std;
int n;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d)
    {
        data = d;
        next = prev = NULL;
    }
};

void push(Node*& head, int x)
{
    if (x <= 0) {
        cout << "list cant be empty.\n";
        exit(1);
    }

    cout << "enter data: ";

    for (int i = 0; i < x; ++i) {
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
            temp->prev = ptr;
        }
    }
}

void printList(Node* list)
{
    while (list != NULL) {
        cout << list->data << " ";
        list = list->next;
    }

    cout << endl;
}

void insert_nth(Node*& head, int pos, int data)
{
    if (pos < 1 || pos > n) {
        cout << "enter valid position.\n";
        exit(1);
    }

    Node* temp = new Node(data);

    if (pos == 1) {
        temp->next = head;
        head->prev = temp;
        head = temp;
    } else {
        Node* ptr = head;

        for (int i = 0; i < pos - 2; ++i) {
            ptr = ptr->next;
        }

        temp->next = ptr->next;
        temp->prev = ptr;
        ptr->next = temp;
        temp->next->prev = temp; //to update the PREV pointer of node next to temp so it points towards temp
    }

    cout << "updated list: ";
    printList(head);
}

int main()
{
    Node* head = NULL;
    cout << "enter nodes to be inserted: ";
    cin >> n;
    push(head, n);
    cout << "current list: ";
    printList(head);

    int pos, data;
    cout << "enter position: ";
    cin >> pos;
    cout << "enter data: ";
    cin >> data;

    insert_nth(head, pos, data);
}

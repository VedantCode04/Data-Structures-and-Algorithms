#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void printlist(Node* list)
{
    while (list != NULL) {
        cout << list->data << " ";
        list = list->next;
    }
    cout << endl;
}

void insertEnd(Node** head, int d)
{

    Node* temp = new Node();
    temp->data = d;
    temp->next = NULL;

    if (*head == NULL) {

        *head = temp;

    } else {

        Node* ptr;
        ptr = *head; // ptr to traverse the list and find the end of the list

        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->next = temp;
    }
}

void insert_nth(Node** head, int data, int pos)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;

    if (pos == 1) {
        temp->next = *head;
        *head = temp;
        return;
    }

    Node* ptr = *head;

    pos--;
    while (pos != 1) {
        ptr = ptr->next;
        pos--;
    }

    temp->next = ptr->next;
    ptr->next = temp;
}

int main()
{
    Node* head = NULL;
    int n;

    cout << "enter total nodes to be inserted: ";
    cin >> n;

    cout << "enter data: ";

    for (int i = 0; i < n; i++) {

        int data;
        cin >> data;
        insertEnd(&head, data);
    }

    cout << "final list 1: ";
    printlist(head);

    int data, pos;
    cout << "enter value to be inserted: ";
    cin >> data;

    cout << "enter position: ";
    cin >> pos;

    if (pos <= n && pos > 0) {
        insert_nth(&head, data, pos);
        printlist(head);
    } else {
        cout << "please enter valid position. \n";
    }

    return 0;
}

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void print(Node* list)
{
    while (list != NULL) {
        cout << list->data << " ";
        list = list->next;
    }
    cout << endl;
}

void insert_at_beg(Node** head, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head; // linking the newNode to the address of the head

    *head = newNode; // now head points towards the newNode
}

int main()
{
    Node* head = NULL;

    cout << "before inserting: ";
    print(head);

    int n;

    cout << "\nenter how many nodes you want to insert at begining: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int data;
        cout << "enter data: ";
        cin >> data;

        insert_at_beg(&head, data);
        print(head);
    }

    cout << "Final list is: ";
    print(head);
}

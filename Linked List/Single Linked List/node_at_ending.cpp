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

int main()
{
    Node* head = NULL;
    int n;

    cout << "enter nodes to be entered at end: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        int data;
        cout << "enter data: ";
        cin >> data;

        insertEnd(&head, data);
        printlist(head);
    }

    cout << "final list: ";

    printlist(head);

    return 0;
}

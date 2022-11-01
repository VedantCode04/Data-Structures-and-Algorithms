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

void insert(Node*& head, int d)
{

    Node* temp = new Node();
    temp->data = d;
    temp->next = NULL;

    if (head == NULL) {

        head = temp;

    } else {

        Node* ptr;
        ptr = head; // ptr to traverse the list and find the end of the list

        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->next = temp;
    }
}

void delete_nth(Node*& head, int pos)
{
    Node* ptr = head; // to  track the position of the nth node
    Node* ptr2 = head; // to track the position of the node before the nth node so we could to link it with the node which is after the nth node

    if (head == NULL) {
        cout << "List is already NULL." << endl;
    }

    else if (pos == 1) {
        head = head->next;
        free(ptr);
        ptr = NULL;
    }

    else {

        while (pos != 1) {
            ptr2 = ptr;
            ptr = ptr->next;
            pos--;
        }

        ptr2->next = ptr->next;

        free(ptr);
        ptr = NULL;
    }
}

int main()
{
    Node* head = NULL;

    int n;
    cout << "insert n: ";
    cin >> n;

    cout << "enter data: ";

    for (int i = 0; i < n; i++) {

        int data;
        cin >> data;
        insert(head, data);
    }

    cout << "List before deletion: ";
    printlist(head);

    cout << "Enter node to be deleted: ";
    int pos;
    cin >> pos;

    if (pos <= n && pos > 0) {

        delete_nth(head, pos);
        cout << "\nList after deletion: ";
        printlist(head);

    } else {
        cout << "Enter valid position" << endl;
    }
}

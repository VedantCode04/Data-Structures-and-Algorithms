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

void insertEnd(Node*& head, int d)
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

void delete_end(Node*& head)
{

    if (head == NULL) {
        cout << "list is already NULL." << endl;
    }

    else if (head->next == NULL) {
        free(head);
        head = NULL;
    }

    else {
        Node* ptr = head;
        Node* ptr2 = head;

        while (ptr->next != NULL) {
            ptr = ptr->next;

            if (ptr->next != NULL) {
                ptr2 = ptr2->next;
            }
        }

        ptr2->next = NULL;

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
        insertEnd(head, data);
    }

    cout << "List before deletion: ";
    printlist(head);

    delete_end(head);

    cout << "\nList after deletion: ";
    printlist(head);
}

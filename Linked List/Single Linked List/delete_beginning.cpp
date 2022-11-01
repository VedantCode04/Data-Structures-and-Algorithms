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

void delete_beg(Node*& head)
{

    if (head == NULL) {
        cout << "node is already empty.";

    } else {
        Node* temp = head;
        head = head->next;
        free(temp); // freeing the data temp pointer contains
        temp = NULL; // deleting the stored address in the temp variable
    }
}

int main()
{
    Node* head = NULL;

    int n;
    cout << "enter total nodes to be deleted: ";
    cin >> n;
    cout << "enter nodes: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        insert(head, data);
    }

    cout << "List before deletion: ";
    printlist(head);

    delete_beg(head);

    cout << "\nList after deletion: ";
    printlist(head);
}

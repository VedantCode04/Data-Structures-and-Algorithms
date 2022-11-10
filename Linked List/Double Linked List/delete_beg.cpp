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

void insertEnd(Node*& head, int n)
{
    cout << "enter data" << endl;

    for (int i = 0; i < n; ++i) {

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

void print(Node* list)
{
    cout << "list is: ";
    while (list != NULL) {
        cout << list->data << " ";
        list = list->next;
    }

    cout << endl;
}

void deleteBeg(Node*& head)
{
    if (head == NULL) {
        cout << "list is already empty." << endl;
        return;
    } else if (head->next == NULL) {
        free(head);
        cout << "\nList is now empty." << endl;
        return;
    }

    Node* ptr = head;
    head = head->next;

    free(ptr);
    head->prev = NULL;

    print(head);
}

int main()
{
    Node* head = NULL;
    int n;
    cout << "enter total nodes to be inserted: ";
    cin >> n;

    insertEnd(head, n);
    print(head);

    cout << "deleting the first node ";
    deleteBeg(head);
}

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

void deleteNth(Node*& head, int pos)
{
    if (head == NULL) {
        cout << "list is already empty." << endl;
        return;
    }

    Node* ptr = head;

    if (pos == 1) {
        if (head->next == NULL) {
            free(head); // if head is the only node in list
            head = NULL;
            cout << "list is now empty" << endl;
            return;
        }
        head = head->next; //changing the pos of the head to the next node
        head->prev = NULL;

    } else {

        for (int i = 1; i < pos; ++i) {
            ptr = ptr->next;
        }

        if (ptr->next == NULL) {
            ptr->prev->next = NULL;
        } else {
            ptr->prev->next = ptr->next; // connecting the NEXT pointer of (pos-1)th node to (pos+1)th node
            ptr->next->prev = ptr->prev; // connecting the PREV pointer (pos+1)th node to (pos-1)th node
        }
    }

    free(ptr);
    ptr = NULL;
    print(head);
    return;
}

int main()
{
    Node* head = NULL;
    int n;
    cout << "enter total nodes to be inserted: ";
    cin >> n;

    insertEnd(head, n);
    print(head);

    int pos;
    cout << "enter position to be deleted: ";
    cin >> pos;
    cout << "deleting the last node ";
    deleteNth(head, pos);
}

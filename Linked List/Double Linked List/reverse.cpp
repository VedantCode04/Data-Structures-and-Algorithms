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

void insert(Node*& head, int n)
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

void reverse(Node*& head)
{
    Node* current = head->next;
    Node* previous = head;

    previous->prev = current;
    previous->next = NULL;

    while (current != NULL) {
        current->prev = current->next;
        current->next = previous;
        previous = current;
        current = current->prev;
    }

    head = previous; //cause current would be now NULL

    print(head);
}

int main()
{
    Node* head = NULL;
    int n;
    cout << "enter total nodes to be inserted: ";
    cin >> n;

    insert(head, n);
    print(head);

    cout << "reverse is: ";
    reverse(head);
} 

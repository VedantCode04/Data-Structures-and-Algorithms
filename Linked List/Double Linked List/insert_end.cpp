#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

void insertEnd(Node*& head, int data)
{
    Node* temp = new Node(data);

    if (head == NULL) {
        head = temp;
    } else {
        Node* ptr = head;
        
        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = temp;
        temp->prev = ptr;
    }
}

void newList(Node*& head, int n){

    cout << "enter data: ";

    for (int i = 0; i < n; ++i)
    {
        int data;
        cin >> data;
        insertEnd(head, data);
    }

    cout << endl;
}

void print(Node* list){
    while(list!=NULL){
        cout << list->data <<" ";
        list = list->next;
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;
    cout << "enter total nodes: ";

    int n;
    cin >> n;
    newList(head, n);

    cout << "your list is ";
    print(head);
}

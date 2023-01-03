//program to implement circular queue
#include <bits/stdc++.h>
using namespace std;
#define MAX 100

class Queue {
    int q[MAX], front = -1, rear = -1;

public:
    bool isFull()
    {
        if (rear == MAX - 1 && front == 0)
            return true;
        else if (rear == front - 1) // checks if the rear is just behind in the circular queue
            return true;
        else
            return false;
    }
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    void enqueue(int data)
    {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        } else {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % MAX; // pushes the rear to right by 1
            q[rear] = data;
        }
    }
    void dequeue()
    {

        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        } else {
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % MAX; // pushes the front to right by 1
            }
        }
    }

    void print()
    {
        if (isEmpty()) {
            cout << "Is empty";
            return;
        }

        int i;
        for (i = front; i != rear; i = (i + 1) % MAX) // i iterates till rear is found
        {
            cout << q[i] << " ";
        }
        cout << q[i] << " "; // to print the rear element
        cout << std::endl;
    }
};

int main()
{
    Queue a;
    int n, data;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> data;
        a.enqueue(data);
    }

    a.print();

    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();

    a.print();
}

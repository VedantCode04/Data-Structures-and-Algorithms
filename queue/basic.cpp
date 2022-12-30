//QUEUE operation FIRST IN FIRST OUT [FIFO]

#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class Queue {
    int front = -1, rear = -1, q[MAX];

public:
    void peek()
    {
        if (front == -1) {
            cout << "Is empty." << endl;
            return;
        }
        cout << q[front] << endl; // return the firt element added [FIFO]
    }

    void print()
    {
        for (int i = 0; i <= rear; ++i) {
            cout << q[i] << " ";
        }
        cout << endl;
    }

    void enqueue(int data)
    {
        if (front == -1)
            front = 0;
        rear++; // acts just like top in stack
        q[rear] = data;
    }

    int dequeue()
    {
        int element = q[front];

        for (int i = 1; i <= rear; ++i) {
            q[i - 1] = q[i]; // loop to push every element 1 position to left is order to remove the first element
        }
        rear--;

        return element; // returns the removed element
    }

    bool isFull()
    {
        if (rear == MAX - 1) {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (rear == -1) {
            return true;
        }
        return false;
    }

    int size()
    {
        return rear + 1;
    }
};

int main()
{
    Queue q;

    q.peek();
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.print();

    int size = q.size();
    for (int i = 0; i < size; i++) {
        cout << q.dequeue() << " deleted" << endl;
    }
    cout << endl;
    if (q.isEmpty()) {
        cout << "Is empty";
    }
}

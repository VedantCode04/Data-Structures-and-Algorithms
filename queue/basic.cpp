#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class Queue {
    int front = -1, rear = -1, q[MAX];

public:
    void enqueue(int data)
    {
        if (front == -1)
            front = 0;
        rear++;
        q[rear] = data;
    }

    void peek()
    {
        if (front == -1)
            cout << "Is empty.";
        cout << q[front] << endl;
    }

    void print()
    {
        for (int i = 0; i <= rear; ++i) {
            cout << q[i] << " ";
        }
        cout << endl;
    }

    int dequeue()
    {
        int element = q[front];

        for (int i = 1; i <= rear; ++i) {
            q[i - 1] = q[i];
        }
        rear--;

        return element;
    }

    bool isFull()
    {
        if (rear = MAX - 1) {
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
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.print();
    cout << q.dequeue() << " is removed." << endl;
    q.peek();

    for (int i = 0; i < 3; ++i) {
        q.dequeue();
    }

    cout << q.isEmpty() << endl;
}

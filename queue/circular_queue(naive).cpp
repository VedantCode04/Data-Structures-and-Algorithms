#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class Queue {
    int front = -1, rear = -1, q[MAX], temp = -1;

public:
    void peek()
    {
        if (front == -1) {
            cout << "Is empty." << endl;
            return;
        }
        cout << q[front] << endl; // return the firt element added [FIFO]
    }

    void enqueue(int data)
    {

        if (front > 0 && isFull()) {
            temp++;
            q[temp] = data;

        } else {
            if (front == -1)
                front = 0;
            rear++; // acts just like top in stack
            q[rear] = data;
        }
    }

    void print()
    {
        for (int i = front; i <= rear; ++i) {
            cout << q[i] << " ";
        }
        if (front > 0 && temp != -1) {
            for (int i = temp; i < front; ++i) {
                cout << q[i] << " ";
            }
        }

        cout << endl;
    }

    void dequeue()
    {
        if (isEmpty()) {
            cout << "Is empty";
            return;
        }
        front++;
    }

    bool isFull()
    {
        if ((rear - front + 1) == MAX) {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (rear - front + 1 == 0) {
            return true;
        }
        return false;
    }

    int size()
    {
        return rear - front + 1;
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
    a.dequeue();
    cout << a.size() << endl;
    a.print();
}

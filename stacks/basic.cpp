#include <iostream>
using namespace std;
#define MAX 5
int stack[MAX]; // global declaration of stack
int top = -1; // indicate stack is empty

void print()
{
    cout << "Stack is : ";
    for (int i = 0; i <= top; ++i) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

void push(int data)
{
    if (top == MAX - 1) {
        cout << "STACK OVERFLOW\n";
        return;
    }
    top++;
    stack[top] = data;
}

void pushStack(int n)
{
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        push(data);
    }
}

void pop()
{
    if (top == -1) {
        cout << "STACK UNDERFLOW\n";
        return;
    }

    top--;
}

void popStack(int n)
{
    for (int i = 0; i < n; ++i) {
        pop();
    }
}

bool isFull()
{
    if (top == MAX - 1) {
        return true; // return 1 if stack is full
    }

    return false;
}

bool isEmpty()
{
    if (top == -1) {
        return true; // return 1 if stack is empty
    }

    return false;
}

int main()
{

    pushStack(5);
    print();
    cout << isFull() << endl; // return 1 if stack is full

    popStack(5);
    print();
    cout << isEmpty() << endl; // return 1 if stack is empty
}

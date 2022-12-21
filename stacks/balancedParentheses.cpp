// balanced parentheses
#include <bits/stdc++.h>
using namespace std;
#define MAX 100

class solution {
    char stack[MAX];
    int top = -1;

    bool isEmpty()
    {
        if (top == -1) {
            return true; // return 1 if stack is empty
        }

        return false;
    }

    void pop()
    {
        if (top == -1) {
            cout << "STACK UNDERFLOW\n";
            return;
        }
        top--;
    }

    void push(char& data)
    {
        if (top == MAX - 1) {
            cout << "STACK OVERFLOW\n";
            return;
        }
        top++;
        stack[top] = data;
    }

public:
    string parentheses;

    bool balanced()
    {
        for (auto& brackets : parentheses) {
            if (brackets == '(' || brackets == '{' || brackets == '[') {
                push(brackets);
            } else {
                if (isEmpty()) {
                    return false;
                } else if (stack[top] == '(' && brackets == ')') {
                    pop();
                } else if (stack[top] == '[' && brackets == ']') {
                    pop();
                } else if (stack[top] == '{' && brackets == '}') {
                    pop();
                } else
                    return false;
            }
        }
        if (isEmpty())
            return true;
        else
            return false;
    }
};

int main()
{
    solution sol;

    cin >> sol.parentheses;

    if (sol.balanced()) {
        cout << "yes";
    } else {
        cout << "no";
    }
}

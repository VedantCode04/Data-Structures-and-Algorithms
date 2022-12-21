// stacks and queues
#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "\nSTACK: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    cout << s.size() << endl;

    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "\nQUEUE: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    cout << q.size() << endl;
}

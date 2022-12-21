// balanced parentheses using STL

#include <bits/stdc++.h>
using namespace std;

map<char, int> m1 = { { '(', -1 }, { '{', -2 }, { '[', -3 }, { ')', 1 }, { '}', 2 }, { ']', 3 } };

string check(string s)
{
    stack<char> stack;
    for (char brackets : s) {
        if (m1[brackets] < 0) { // checks if the brackets is opening or not
            stack.push(brackets);
        } else {
            if (stack.empty())
                return "NO"; // if the first char is of closing type, then unbalanced

            char top = stack.top();
            stack.pop();
            if (m1[top] + m1[brackets] != 0) { // checks if the opening and closing brackets are of the same type
                return "NO";
            }
        }
    }

    if (stack.empty())
        return "YES";
    else
        return "NO";
}

int main()
{
    string s;
    cin >> s;
    cout << check(s) << endl;
}

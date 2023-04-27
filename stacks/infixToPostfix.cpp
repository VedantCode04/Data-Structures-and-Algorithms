#include <bits/stdc++.h>
using namespace std;
stack<char> s;

int precedence(char c)
{
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else {
        return 3;
    }
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    } else {
        return false;
    }
}

string infixToPostfix(string expr)
{

    string postfix = "";

    for (int i = 0; i < expr.length(); ++i) {
        if (isOperator(expr[i])) {
            if(s.empty()){
                s.push(expr[i]); 
            } else if (precedence(expr[i]) > precedence(s.top()))
            {
                s.push(expr[i]); 
            } else {
                while( !s.empty() && precedence(s.top()) >= precedence(expr[i])){
                    char temp = s.top();
                    s.pop();
                    postfix = postfix + temp;
                }

                s.push(expr[i]);
            }
        } else {
            postfix = postfix + expr[i];
        }
    }

    while(!s.empty()){
        char temp = s.top();
        postfix = postfix + temp;
        s.pop();
    }

    return postfix;
}

int main()
{
    string s;
    cin >> s;

    cout << infixToPostfix(s);
}

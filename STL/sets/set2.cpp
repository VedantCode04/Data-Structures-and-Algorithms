#include <bits/stdc++.h>
using namespace std;

void print(unordered_set<string>& set)
{
    for (auto& a : set) {
        cout << a << " ";
    }

    cout << endl;
}

int main()
{
    unordered_set<string> set;
    set.insert("abc"); // o(1) insertion
    set.insert("def");
    set.insert("ghi");
    set.insert("aab");
    set.insert("def"); // only unique values
    print(set);

    int q = set.size();
    string s;
    while (q--) {
        cin >> s;
        auto result = set.find(s);
        if (result != set.end()) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}
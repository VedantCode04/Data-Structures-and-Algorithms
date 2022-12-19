#include <bits/stdc++.h>
using namespace std;

void print(set<string>& set)
{
    for (auto& a : set) {
        cout << a << " ";
    }

    cout << endl;
}

int main()
{
    set<string> set; // sets element in sorted order

    set.insert("abc"); // o(logN) insertion
    set.insert("abde");
    set.insert("aab");
    print(set);
    auto result = set.find("aaab");

    if (result != set.end()) {
        cout << (*result) << endl;
    } else {
        cout << "not found\n";
    }

    set.erase("aab");
    print(set);

    set.clear();
    print(set);
}

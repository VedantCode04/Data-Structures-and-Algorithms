#include <bits/stdc++.h>
using namespace std;

void print(multiset<string>& set)
{
    for (auto& a : set) {
        cout << a << " ";
    }

    cout << endl;
}

int main()
{
    multiset<string> set; // multiple values allowed

    set.insert("abc"); // o(logN) insertion
    set.insert("def");
    set.insert("ghi");
    set.insert("aab");
    set.insert("def");
    set.insert("ghi");

    print(set);

    auto it = set.find("def");

    if (it != set.end()) {
        set.erase(it); // delete only 1st "it" in set
    }

    print(set);

    set.erase("ghi"); // delete every "ghi" in set

    print(set);
}
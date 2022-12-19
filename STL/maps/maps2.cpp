#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> m; // string is a key, int is frequency of the string
    string s;
    for (int i = 0; i < 8; ++i) {
        cin >> s;
        m[s]++; // initially m[s] = 0
    }

    for (auto& a : m) {
        cout << a.first << " " << a.second << endl;
    }
}

// calculate strings in lexiograpgic order
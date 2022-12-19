#include <bits/stdc++.h>
using namespace std;

void printMap(map<int, string>& map)
{
    cout << "Map is: " << endl;
    for (auto& a : map) {
        cout << a.first << " " << a.second << endl;
    }
}

int main()
{
    map<int, string> m;

    m[1] = 'A';
    m[2] = 'B';
    m[3] = 'C';

    printMap(m);

    cout << "After duplicate key ";

    m[2] = "VEDANT";

    printMap(m);

    cout << "\nfind function: ";
    auto it = m.find(3);

    cout << it->first << " " << it->second << endl;

    cout << "\nerase function: ";
    m.erase(2);

    printMap(m);

    cout << "\nclear function: ";
    m.clear();
    printMap(m);
}

#include <bits/stdc++.h>
using namespace std;

void printMap(map<pair<string, string>, vector<int>>& map)
{
    cout << "Map is : " << endl;

    for (auto& value : map) {
        auto& pair = value.first;
        auto& vector = value.second;

        cout << ">>" << pair.first << " " << pair.second << endl;

        for (auto& val : vector) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    map<pair<string, string>, vector<int>> m; // nesting not allowed in unordered_maps as they use hashtables, while ordered maps are comparison based thus allowed

    int n;
    cout << "Enter total map elements: ";
    cin >> n;

    string s1, s2;
    int x;
    for (int i = 0; i < n; ++i) {
        cout << "Enter pair: ";
        cin >> s1 >> s2;
        cout << "Enter vec size: ";
        cin >> x;
        cout << "Vec elements: ";

        for (int i = 0; i < x; ++i) {
            int data;
            cin >> data;

            m[{ s1, s2 }].emplace_back(data);
        }
    }

    printMap(m);
}

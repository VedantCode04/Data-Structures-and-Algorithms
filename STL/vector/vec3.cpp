#include <bits/stdc++.h>
using namespace std;

void enterVec(vector<pair<string, int>>& v)
{
    cout << "Enter value: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string a;
        int b;
        cin >> a >> b;
        v.push_back({ a, b });
    }

    cout << endl;
}

void printVec(vector<pair<string, int>>& v)
{
    cout << "vector is: " << endl;
    vector<pair<string, int>>::iterator it = v.begin();

    for (it = v.begin(); it != v.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}

int main()
{

    vector<pair<string, int>> v;

    enterVec(v);
    printVec(v);

    cout << "size after: " << v.size() << endl;
}

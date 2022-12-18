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

    for (auto value : v) {
        cout << value.first << " " << value.second << endl;
    }

    vector<pair<string, int>>::iterator it;

    for (it = v.begin(); it != v.end(); ++it) {
        cout << it->first << " " << it->second;
    }
}

void enterVofV(vector<vector<int>>& v)
{
    int m;
    cout << "Total vector: ";
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cout << "Enter elements of vector: ";
        int n;
        cin >> n;
        vector<int> temp;
        for (int i = 0; i < n; ++i) {
            int b;
            cin >> b;
            temp.push_back(b);
        }

        v.push_back(temp);
    }
}

void printVofV(vector<vector<int>>& v)
{
    int i = 0;
    for (auto value : v) {

        cout << "Size of vector " << i << ":[" << value.size() << "] ";
        for (auto value1 : value) {

            cout << value1 << " ";
        }
        i++;
        cout << endl;
    }
}

int main()
{

    vector<pair<string, int>> v;

    vector<vector<int>> a;
    enterVofV(a); // input for vector of vector
    printVofV(a); // print vector of vector
    enterVec(v); // input for vector of pairs
    printVec(v); // print vector of pairs
}

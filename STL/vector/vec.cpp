#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int>& v)
{
    cout << "size: " << v.size() << endl;
    for (auto value : v) {
        cout << value << " ";
    }

    cout << endl;
}

void deleteVec(vector<int>& v)
{
    cout << "size before: " << v.size() << endl;

    while (!v.empty()) {
        v.pop_back(); // delete entire vector
    }

    cout << endl;
}

void enterVec(vector<int>& v)
{
    cout << "Enter value: ";
    int a;
    cin >> a;

    for (int i = 0; i < a; ++i) {
        int b;
        cin >> b;

        v.emplace_back(b); // more efficient than push_back();
    }

    cout << endl;
}

int main()
{

    vector<int> v;

    enterVec(v);
    printVec(v);
    deleteVec(v);

    cout << "size after: " << v.size() << endl;
}

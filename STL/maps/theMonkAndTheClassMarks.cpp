// the monk and the class marks
//  given the marks of the students, print the marks in decreasing order and if two student have same marks, then print them in the lexiographical order

#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, multiset<string>> m;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string name;
        int marks;
        cin >> name >> marks;
        m[marks].insert(name);
    }

    auto it = --m.end();

    while (true) {
        auto& students = it->second;
        int marks = it->first;

        for (auto student : students) {
            cout << student << " " << marks << endl;
        }

        if (it == m.begin()) {
            break;
        }
        it--;
    }
}

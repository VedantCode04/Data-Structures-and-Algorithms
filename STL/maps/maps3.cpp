#include <bits/stdc++.h>
using namespace std;

void print(unordered_map<int, char>& m)
{
    for (auto& a : m) {
        cout << a.first << " " << a.second << endl;
    }
}
int main()
{

    unordered_map<int, char> m = { { 1, 'a' }, { 2, 'b' }, { -1, 'v' } };
    print(m);

    auto result = m.find(-2);

    if (result != m.end()) {
        cout << result->first << " " << result->second << endl;
    } else {
        cout << "Not found\n";
    }

    m.erase(-1);
    print(m);

    m.clear();
    print(m);
}
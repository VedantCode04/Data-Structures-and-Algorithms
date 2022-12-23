// NGE using stack [o(n)]
#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> v)
{
    vector<int> nge(v.size());
    stack<int> s;

    for (int i = v.size() - 1; i >= 0; --i) {
        while (!s.empty() && s.top() < v[i]) {
            s.pop();
        }

        if (s.size() == 0) {
            nge[i] = -1;
            s.push(v[i]);
        } else {

            nge[i] = s.top();
            s.push(v[i]);
        }
    }

    return nge;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.emplace_back(x);
    }

    vector<int> nge = NGE(v);

    for (int i = 0; i < n; ++i) {
        cout << v[i] << "->" << nge[i] << endl;
    }

    return 0;
}

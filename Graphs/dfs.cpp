#include <bits/stdc++.h>
using namespace std;
#define loop(start, end) for (int i = start; i < end; ++i)
#define loop1(start, end) for (int i = start; i <= end; ++i)
#define loop2(start, end) for (int i = start; i >= end; --i)
#define loop3(start, end) for (int i = start; i > end; --i)
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define qi queue<int>
#define si stack<int>
#define ll long long

void adjList(vi list[], int E, int V)
{
    int u, v;
    loop(0, E)
    {
        cin >> u >> v;
        list[u].pb(v);
        list[v].pb(u);
    }

    loop(0, V)
    {
        cout << i << " -> ";
        for (auto a : list[i]) {
            cout << a << " ";
        }
        cout << endl;
    }
}

void dfs(int node, vi list[], int visit[], vi& sol)
{
	//0 based indexing graph i.e graph starting from 0, 1, 2....

    visit[node] = 1; //marking the node as visited
    sol.pb(node); //pushing the node into the sol vector

    for (auto a : list[node]) { //checking for every edges connected to the node 
        if (visit[a] == 0) {
            dfs(a, list, visit, sol); //recussively call dfs for the unvisited Node
        }
    }
	
	//Time complexity: O(degrees) + O(nodes) = O(2*Edges) + O(nodes) because loop if iterated over every degree of the node[O(degrees)] and this happens for every node [O(nodes)]
	//Space Complexity: O(V) . v = vertices/nodes for making an visited array 
}

vi graphDfs(int start, vi list[], int visit[])
{
    vi sol;

    dfs(start, list, visit, sol);

    return sol;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vi list[V];
    int visit[V] = { 0 };
    adjList(list, E, V);
    int start;
    cin >> start;

    vi sol = graphDfs(start, list, visit);

    for (auto a : sol) {
        cout << a << " ";
    }
    
    return 0;
}

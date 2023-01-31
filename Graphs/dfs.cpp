#include <bits/stdc++.h>
using namespace std;
#define loop(start, end) for (int i = start; i < end; ++i)
#define loop1(start, end) for (int i = start; i <= end; ++i)
#define loop2(start, end) for (int i = start; i >= end; --i)
#define loop3(start, end) for (int i = start; i > end; --i)
#define pb push_back
#define vi vector<int>
#define qi queue<int>
#define si stack<int>
#define ll long long

int visit[9] = {0};
vi vec;

void adjList(vi list[], int edges)
{
    loop(0, edges)
    {
        int u, v;
        cin >> u >> v;
        list[u].pb(v);
        list[v].pb(u);
    }

    // adjacency list o(edges*2) space complexit0
}

vi dfs(vi list[], int node)
{
	
    visit[node] = 1;
    vec.pb(node); //store the value in vector

    for(auto a : list[node]){ //traversing every node connected to the list[node]
    	if(visit[a] == 0){ //if the instance a is not visited, then perform dfs
    		dfs(list, a); //recussively traversing for 
    	}
    }

    return vec;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vi list[nodes];

    adjList(list, edges);

    cout << "graph is " << endl;

    vi sol = dfs(list, 0);

    for (auto a : sol)
        cout << a << " ";

    return 0;
}

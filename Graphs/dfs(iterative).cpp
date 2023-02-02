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

vi graphDfs(vi list[], int V, int start)
{
    int visit[V] = {0};

    visit[start] = 1;

    si s; // stack for storing elements for dfs
    s.push(start); //pushing the starting element in the stack

    vi vec; //to store the ans

    while(!s.empty()){
    	int temp = s.top(); //storing the top element in temp var
    	s.pop(); //removing the top element
    	vec.pb(temp); //pushing the temp in the vec

    	for(int a: list[temp]){ //iterating over all nodes connected to the TEMP in the list
    		if(visit[a] == 0){
    			visit[a] = 1; 
    			s.push(a);
    			//marking 'a' as visted and pushing it to the stack
    		}
    	}

    }

    return vec;
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

    vi sol = graphDfs(list, V, start);

    for (auto a : sol) {
        cout << a << " ";
    }
    
    return 0;
}

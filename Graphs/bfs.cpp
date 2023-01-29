#include <bits/stdc++.h>
using namespace std;
#define loop(start, end) for (int i = start; i < end; ++i)
#define pb push_back
#define vi vector<int>
#define qi queue<int>
#define si stack<int>

void adjList(vi list[], int edges){
	loop(0, edges){
		int u, v;
		cin >> u >> v;
		list[u].pb(v);
		list[v].pb(u);
	}

	//adjacency list o(edges*2) space complexit0
}

vi bfs(vi list[], int nodes){
	bool visit[nodes] = {0}; //visited array to keep track of the nodes which are visited or not
	visit[0] = 1; //1 based indexing in the graph i.e graph starting with 1
	qi q;
	q.push(0); //push the starting node

	vi bfs; //making a vector to store the bfs result

	while(!q.empty()){
		int node = q.front();
		q.pop();
		bfs.push_back(node);

		for(auto value: list[node]){
			if(visit[value] == 0){
				visit[value] = 1;
				q.push(value); //push the node if it is not visited
			}
		}
	}

	return bfs;
}

void printGraph(vi list[], int nodes){
	loop(0, nodes){
		cout << i << "-> ";
		for(auto a : list[i]){
			cout << a << " ";
		}

		cout << endl;
	}
}

int main(){
	int nodes, edges;
	cin >> nodes >> edges;

	vi list[nodes];

	adjList(list, edges);

	cout << "graph is " << endl;
	printGraph(list, nodes);

	vi sol = bfs(list, nodes);

	for(auto a : sol)
		cout << a << " ";

	return 0;
}

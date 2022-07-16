#include <bits/stdc++.h>
using namespace std;


int main() {
    // m - edge, n - node
	int n, m;
	cin >> n >> m;

	// declare the adjacent matrix
	vector<int> adj[n+1];

    // for undirected graph
	for(int i = 0;i<m;i++) {
        // take edges as input
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}

    /* for directed graph
	for(int i = 0;i<m;i++) {
        // take edges as input
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v);
	}*/

    /* for weighted graph
    vector<pair<int,int>> adj[n+1];
	for(int i = 0;i<m;i++) {
        // take edges as input
	    int u, v, wt;
	    cin >> u >> v >> wt;
	    adj[u].push_back({v,wt});
	    adj[v].push_back({u,wt});
	}*/

	return 0;
}

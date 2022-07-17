#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &storeTopo) {

        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, storeTopo);
            }
        }

        storeTopo.push(node);
    }
public:
	vector<int> topoSort(int V, vector<int> adj[]){
        stack<int> storeTopo;
	    vector<int> vis(V, 0); // 0 based indexing
        for(int i = 0;i<V;i++) {
            if(!vis[i]){
                dfs(i, vis, adj, storeTopo);
            }
        }

        vector<int> res;

        while(!storeTopo.empty()){
            int val = storeTopo.top();
            storeTopo.pop();
            res.push_back(val);
        }

	    return res;
	}
};

/*
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}*/

int main()
{
    int N = 6;

    vector<int> adj[5 + 1];

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    vector<int> res = obj.topoSort(6, adj);

    cout << "Toposort of the given graph is:" << endl;
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
    }

    return 0;
}

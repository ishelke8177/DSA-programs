#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {

        vis[node] = 1;

        for(auto it : adj[node]) {

            if(!vis[it]) {
                checkForCycle(it,node, vis, adj);
            }
            else if(parent != it)
                return true;

        }

        return false;
    }
public:
	bool hasCycle(int V, vector<int> adj[]){

	    vector<int> vis(V+1, 0);

        for(int i = 1;i<=V;i++) {
            if(checkForCycle(i, -1, vis, adj))
                return true;
        }
	    return false;
	}
};

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    vector<int> adj[6];

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,2,4);

    Solution obj;
    int num=obj.hasCycle(5, adj);

    if(num==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool checkForCycle(int i, int V, vector<int> adj[], vector<int>& visited){
        // Create a queue for BFS
        queue<pair<int, int>> q;
        visited[i] = true;
        q.push({i, -1});

        while(!q.empty()){
            // access the front node of a queue
            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            for(auto it:adj[node])
            {
                if(!visited[it])
                {
                    // mark as visited
                    visited[it] = true;
                    q.push({it, node});
                }
                // check if the visited node is parent/previous or not
                else if(par != it)
                    return true;
            }
        }

        return false;
    }

    bool hasCycle(int V, vector<int> adj[]){
        vector<int> vis(V+1,0);
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                if(checkForCycle(i,V,adj,vis))
                    return true;
            }
        }
    }
};

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    // adjacency list
    vector<int> adj[5];

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,2,4);

    /*addEdge(adj,1, 0);
    addEdge(adj,0, 2);
    addEdge(adj,2, 1);
    addEdge(adj,0, 3);
    addEdge(adj,3, 4);*/

    Solution obj;
    int num=obj.hasCycle(5, adj);

    if(num==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}

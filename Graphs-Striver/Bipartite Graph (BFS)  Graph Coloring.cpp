#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    bool bipertiteBFS(int src, vector<int>& color, vector<int> adj[]){
        color[src] = 1;
        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it:adj[node]){
                if(color[it] == -1){
                    // color it with the opposite of its adjacent
                    color[it] = 1 - color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }

        return true;
    }

    bool checkBipertite(int n, vector<int> adj[]){
        // to fill one of the two colors
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            // not coloured
            if(color[i] == -1){
                if(!bipertiteBFS(i, color, adj)){
                    return false;
                }
            }
        }

        return true;
    }
};

//void addEdge(vector<int> adj[], int u, int v){

//}

int main(){
    int n,edges;
    cout<<" Number of Nodes : ";
    cin>>n;
    cout<<" Number of Edges : ";
    cin>>edges;
    vector<int> adj[n];

    for(int i=0;i<edges;i++){
        int u, v;
        cout<<"Enter edge values : ";
        cin>>u>>v;
        //addEdge(adj,e1,e2);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;

    if(obj.checkBipertite(n,adj))
        cout<<"Yes";
    else
        cout<<"No";

    return 0;
}

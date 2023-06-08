//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool check(int i, vector<int> &vis, vector<int> adj[], int v){
        if(vis[i] == 1) return true;
        if(vis[i] == 0){
            vis[i] = 1;
            for(auto j : adj[i]){
                if(check(j, vis, adj, v)) return true;
            }
        }
        vis[i] = 2;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int> vis(v, 0);
        
        for(int i = 0; i < v; i++){
            if(check(i, vis, adj, v)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
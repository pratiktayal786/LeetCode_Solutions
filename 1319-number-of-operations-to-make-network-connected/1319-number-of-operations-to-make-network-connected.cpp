class Solution {
public:
    void dfs(int i, vector<int> adj[], vector<int> &vis){
        vis[i] = 1;
        for(auto j : adj[i]){
            if(!vis[j]){
                dfs(j, adj, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1) return -1;
        vector<int> vis(n, 0);
        vector<int> adj[n];
        
        for(auto i : connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                ans++;
            }
        }
        return ans-1;
    }
};
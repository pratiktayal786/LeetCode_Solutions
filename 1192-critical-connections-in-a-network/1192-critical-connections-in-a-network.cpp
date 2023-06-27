class Solution {

    int timer = 0;
    
public:
    
    void dfs(int node, int parent, vector<int> adj[], 
             vector<int> &vis, vector<int> &time, 
            vector<int> &low, vector<vector<int>> &bridges){
        vis[node] = 1;
        time[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it, node, adj, vis, time, low, bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > time[node]){
                    bridges.push_back({node, it});
                }
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];
        vector<int> vis(n, 0);
        vector<int> time(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        dfs(0, -1, adj, vis, time, low, bridges);
        return bridges;
    }
};
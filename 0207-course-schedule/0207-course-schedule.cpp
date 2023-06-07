class Solution {
public:
    
    bool isCycle(vector<int> adj[], vector<int> &vis, int i){
        if(vis[i] == 1) return true;
        
        if(vis[i] == 0){
            vis[i] = 1;
            for(auto j : adj[i]){
                if(isCycle(adj, vis, j)) return true;
            }
        }
        vis[i] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> vis(n,0);
        
        for(auto i : pre){
            adj[i[0]].push_back(i[1]);
        }
        
        for(int i = 0; i < n; i++){
            if(isCycle(adj, vis, i)) return false;
        }
        
        return true;
    }
};
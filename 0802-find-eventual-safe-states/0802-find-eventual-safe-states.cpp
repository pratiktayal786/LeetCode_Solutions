class Solution {
public:
    
    bool dfs(int i, vector<int> &vis, vector<vector<int>> &graph, vector<int> &ans){
        vis[i] = 1;
        
        for(auto j : graph[i]){
            if((vis[j] == 0 && dfs(j, vis, graph, ans)) || vis[j] == 1) return true;
        }
        vis[i] = 2;
        ans.push_back(i);
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> ans;
        vector<int> vis(n, 0);
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 0) dfs(i, vis, graph, ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
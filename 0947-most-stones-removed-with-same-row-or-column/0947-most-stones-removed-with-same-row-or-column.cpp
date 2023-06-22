class Solution {
public:
    
    void dfs(int ind, vector<vector<int>>& stones, vector<int> &vis, int &ans){
        vis[ind] = 1;
        
        for(int i = 0; i < stones.size(); i++){
            if(!vis[i] && 
               ((stones[i][0] == stones[ind][0]) 
                || (stones[i][1] == stones[ind][1]))
              )
            {
                ans++;
                dfs(i, stones, vis, ans);
            }  
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        vector<int> vis(n, 0);
        int ans = 0;
        
        for(int i = 0;  i < n; i++){
            if(!vis[i]){
                dfs(i, stones, vis, ans);
            }
        }
        return ans;
    }
};
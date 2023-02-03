class Solution {
public:
    
    void solve(int ind, int k, int n, 
               vector<int> ds, vector<vector<int>> &ans){
        if(ind == 10){
            if(k == 0 && n == 0) ans.push_back(ds);
            return;
        }
        if(k == 0 && n == 0) 
        {
            ans.push_back(ds);
            return;
        }
        solve(ind+1, k, n, ds, ans);
        ds.push_back(ind);
        solve(ind+1, k-1, n-ind, ds, ans);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        if(k <= 0 || n <= 0 || n > 45) return {};
        
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1, k, n, ds, ans);
        return ans;
    }
};
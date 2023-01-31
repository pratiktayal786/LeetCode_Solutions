class Solution {
public:
    
    void solve(vector<int> &candidates, int tar, int ind, int sum, 
               vector<int> ds, vector<vector<int>> &ans){
        
        if(sum > tar || ind == candidates.size()) return;
        if(sum == tar){
            ans.push_back(ds);
            return;
        }
        
        solve(candidates, tar, ind+1, sum, ds, ans);
        ds.push_back(candidates[ind]);
        solve(candidates, tar, ind, sum+candidates[ind], ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        solve(candidates, target, 0, 0, ds, ans);
        return ans;
    }
};
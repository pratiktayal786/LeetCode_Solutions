class Solution {
public:
    
    void solve(vector<int> &nums, int ind, 
               vector<int> ds, vector<vector<int>> &ans){
        if(ind == nums.size()){
            ans.push_back(ds);
            return;
        }
        solve(nums, ind+1, ds, ans);
        ds.push_back(nums[ind]);
        solve(nums, ind+1, ds, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(nums, 0, ds, ans);
        return ans;
    }
};
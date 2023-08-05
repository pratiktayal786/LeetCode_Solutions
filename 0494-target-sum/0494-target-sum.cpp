class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i, int total, int tar, vector<int> &arr){
        if(total == tar && i == arr.size()) return 1;
        if(i == arr.size()) return 0;
        if(dp[i][total+1000] != -1) return dp[i][total+1000];
        return dp[i][total+1000] = solve(i+1, total+arr[i], tar, arr) +
            solve(i+1, total-arr[i], tar, arr);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.resize(nums.size()+1, vector<int> (2005, -1));
        return solve(0, 0, target, nums);
    }
};
class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(auto i : nums) sum += i;
        if(sum % 2 == 1) return false;
        
        int k = sum/2;
        vector<vector<bool>> dp(n, vector<bool> (k+1, false));
        
        for(int i = 0; i < n; i++) dp[i][0] = true;
        if(nums[0] <= k) dp[0][nums[0]] = true;
        
        for(int i = 1; i < n; i++){
            for(int tar = 0; tar <= k; tar++){
                bool taken = false, notTaken = false;
                if(nums[i] <= tar){
                    taken = dp[i-1][tar-nums[i]];
                }
                notTaken = dp[i-1][tar];
                dp[i][tar] = (taken || notTaken);
            }
        }
        return dp[n-1][k];
    }
};
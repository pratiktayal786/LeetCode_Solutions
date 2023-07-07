class Solution {
public:
    
    int solve(int x, int n, vector<int> &dp){
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(x+1, n-1, dp) + solve(x+2, n-2, dp);
    }
    int climbStairs(int n) {
        if(n <= 2) return n;
        
        vector<int> dp(n+1, -1);
        return solve(0, n, dp);
    }
};
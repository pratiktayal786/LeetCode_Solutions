class Solution {
public:
    
    vector<vector<int>> dp;
    
    int solve(int i, vector<int> &arr, int amt){
        if(amt == 0) return 0;
        if(amt < 0 || i < 0) return INT_MAX-1;
        if(dp[i][amt] != -1) return dp[i][amt];
        
        int take = 1+solve(i, arr, amt-arr[i]);
        int notTake = solve(i-1, arr, amt);
        return dp[i][amt] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n+1, vector<int> (amount+1, -1));
        int ans = solve(n-1, coins, amount);
        return (ans < INT_MAX-1 ? ans : -1);
    }
};
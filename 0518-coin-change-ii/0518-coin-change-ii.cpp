class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i, int amt, vector<int> &arr){
        if(amt == 0) return 1;
        if(i == arr.size()) return 0;
        
        if(dp[i][amt] != -1) return dp[i][amt];
        
        if(arr[i] > amt){
            return dp[i][amt] = solve(i+1, amt, arr);     
        }
        return dp[i][amt] = solve(i, amt-arr[i], arr) + solve(i+1, amt, arr);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n+1, vector<int> (amount+1, -1));
        return solve(0, amount, coins);
    }
};
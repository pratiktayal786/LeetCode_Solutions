class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int i = 0; i < n; i++){
            dp[0][i] = arr[0][i];
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                
                int left = INT_MAX, right = INT_MAX;
                
                int up = dp[i-1][j];
                if(j-1 >= 0) left = dp[i-1][j-1];
                if(j+1 < n) right = dp[i-1][j+1];
                dp[i][j] = arr[i][j] + min({up, left, right});
            }
        }
        
        int ans = INT_MAX;
        for(auto i : dp[n-1]){
            ans = min(ans, i);
        }
        return ans;
    }
};
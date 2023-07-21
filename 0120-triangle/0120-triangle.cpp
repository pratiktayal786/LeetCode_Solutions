class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp){
                
        int n = arr.size();
        
        if(i == n-1){
            return arr[i][j];
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = min(solve(i+1, j, arr, dp), 
                                  solve(i+1, j+1, arr, dp));
        
        int diagonal = min(solve(i+1, j, arr, dp), 
                                  solve(i+1, j+1, arr, dp));
        return dp[i][j] = arr[i][j] + min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, 0, triangle, dp);
    }
};
class Solution {
public:
    
    int longestCommonSubsequence(string t1, string t2) {
        
        int n = t1.size(), m = t2.size();
        vector<vector<int>> dp;
        dp.resize(t1.size()+1, vector<int> (t2.size()+1, -1));
        
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;
        
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(t1[i-1] == t2[j-1]) dp[i][j] =  1 + dp[i-1][j-1];
                else dp[i][j] = max(0+dp[i][j-1], 0+dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
};
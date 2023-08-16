class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(string &t1, string &t2, int n, int m){
        if(n == 0 || m == 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(t1[n-1] == t2[m-1]) return dp[n][m] =  1 + solve(t1, t2, n-1, m-1);
        else return dp[n][m] = max(0+solve(t1, t2, n-0, m-1), 0+solve(t1, t2, n-1, m-0));
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        dp.resize(text1.size()+1, vector<int> (text2.size()+1, -1));
        return solve(text1, text2, text1.size(), text2.size());
    }
};
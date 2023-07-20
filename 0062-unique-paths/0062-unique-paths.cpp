class Solution {
public:
    
    int uniquePaths(int n, int m) {
        
        vector<int> dp(m, 0);
        
        for(int i = 0; i < n; i++){
            vector<int> temp(m, 0);
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) temp[j] = 1;
                else{
                    if(i > 0) temp[j] = dp[j];
                    if(j > 0) temp[j] += temp[j-1];
                }
            }
            dp = temp;
        }
        return dp[m-1];
    }
};
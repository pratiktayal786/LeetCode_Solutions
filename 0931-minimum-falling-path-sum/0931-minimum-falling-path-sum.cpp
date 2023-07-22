class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        
        int n = arr.size();
        vector<int> upper(n), cur(n, 0);
        
        for(int i = 0; i < n; i++){
            upper[i] = arr[0][i];
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                
                int left = INT_MAX, right = INT_MAX;
                
                int up = upper[j];
                if(j-1 >= 0) left = upper[j-1];
                if(j+1 < n) right = upper[j+1];
                cur[j] = arr[i][j] + min({up, left, right});
            }
            upper = cur;
        }
        
        int ans = INT_MAX;
        for(auto i : upper){
            ans = min(ans, i);
        }
        return ans;
    }
};
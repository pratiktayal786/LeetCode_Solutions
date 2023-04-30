class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>>& grid){
        
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return 0;
        
        int val = grid[i][j];
        vector<vector<int>> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        grid[i][j] = 0;
        
        for(int k = 0; k < 4; k++){
            int newR = i+moves[k][0];
            int newC = j+moves[k][1];
            val += solve(newR, newC, grid);
        }
        return val;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    int val = solve(i, j, grid);
                    ans = max(ans, val);
                }
            }
        }
        if(ans == INT_MIN) return 0;
        return ans;
    }
};
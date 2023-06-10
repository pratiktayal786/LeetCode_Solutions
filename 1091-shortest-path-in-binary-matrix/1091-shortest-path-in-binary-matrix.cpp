class Solution {
public:
    
    bool isValid(int i, int j, int n, vector<vector<int>>& grid, vector<vector<bool>> &vis)     {
        return (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0 && !vis[i][j]);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        int ans = 0;
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        if(grid[0][0] == 0){
            q.push({0,0});
            vis[0][0] = true;
        }
        
        while(!q.empty()){
            int m = q.size();
            ans++;
            
            for(int k = 0; k < m; k++){
                auto [x,y] = q.front();
                q.pop();
                if(x == n-1 && y == n-1) return ans;
                for(int r = x-1; r <= x+1; r++){
                    for(int c = y-1; c <= y+1; c++){
                        if(isValid(r, c, n, grid, vis)){
                            q.push({r,c});
                            vis[r][c] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
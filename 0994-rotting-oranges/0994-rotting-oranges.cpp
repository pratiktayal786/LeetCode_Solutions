class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = -1;
        int fresh = 0;
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1) fresh++;
            }
        }

        
        vector<pair<int,int>> dirs = {{1,0}, {-1, 0}, {0,-1}, {0,1}};
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx,dy] : dirs){
                    int i = x+dx;
                    int j = y+dy;
                    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1){
                        grid[i][j] = 2;
                        fresh--;
                        q.push({i,j});
                    }
                }
            }
                ans++;
        }
        if(fresh != 0) return -1;
        return (ans == -1) ? 0 : ans ;
    }
};
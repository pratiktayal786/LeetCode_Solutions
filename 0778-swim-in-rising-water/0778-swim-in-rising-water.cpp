class Solution {
public:
    
    bool isValid(int i, int j, int n){
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int> (n, 0));
        using pipii = pair<int,pair<int,int>>;
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        int ans = 0;
        vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        pq.push({grid[0][0], {0,0}});
        vis[0][0] = 1;
        
        while(!pq.empty()){
            auto [dpt, dirs] = pq.top();
            int x = dirs.first;
            int y = dirs.second;
            pq.pop();
            ans = max(ans, dpt);
            if(x == n-1 && y == n-1) return ans;
            for(auto [dx, dy] : dir){
                int i = x+dx;
                int j = y+dy;
                if(isValid(i,j,n) && !vis[i][j]){
                    vis[i][j] = 1;
                    pq.push({grid[i][j], {i,j}});
                }
            }
        }
        return ans;
    }
};
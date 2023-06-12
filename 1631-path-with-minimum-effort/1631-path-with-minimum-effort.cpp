class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        using pipii = pair<int,pair<int,int>>;
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        
        while(!pq.empty()){
            auto [weight, xy] = pq.top();
            pq.pop();
            int x = xy.first;
            int y = xy.second;
            if(x == n-1 && y == m-1) return weight;
            for(auto [dx,dy] : dirs){
                int i = dx+x;
                int j = dy+y;
                if(i < 0 || j < 0 || i >= n || j >= m) continue;
                int newWeight = max(weight, abs(heights[i][j]-heights[x][y]));
                if(dist[i][j] <= newWeight) continue;
                dist[i][j] = newWeight;
                pq.push({newWeight, {i,j}});
            }
        }
        return 0;
    }
};
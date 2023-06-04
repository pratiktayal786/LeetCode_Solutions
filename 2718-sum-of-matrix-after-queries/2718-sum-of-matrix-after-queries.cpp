class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
    
        int cnt[2] = {n,n};
        bool vis[2][100001] = {};    
        long long ans = 0;
        
        for(int i = q.size()-1; i >= 0; i--){
            int type = q[i][0], ind = q[i][1], val = q[i][2];
            if(!vis[type][ind]){
                ans += val * cnt[!type];
                cnt[type]--;
                vis[type][ind] = true;
            }
        }
        return ans;
    }
};
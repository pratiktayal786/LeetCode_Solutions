class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> adj[n+1];
        using pii = pair<int,int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n+1, INT_MAX);
    
        for(auto i : times){
            adj[i[0]].push_back({i[1], i[2]});
        }
        pq.push({0, k});
        
        dist[k] = 0;
        
        while(!pq.empty()){
            auto [time, stat] = pq.top();
            pq.pop();
            
            for(auto i : adj[stat]){
                if(dist[i.first] > time+i.second){
                    dist[i.first] = i.second+time;
                    pq.push({i.second+time, i.first});  
                } 
            }
        }
        
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
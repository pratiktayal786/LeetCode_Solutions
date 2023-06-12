class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dist(n, INT_MAX);
        
        for(auto i : flights){
            adj[i[0]].push_back({i[1], i[2]});
        }
        pq.push({0, src, 0});
        dist[src] = 0;
        
        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();
            int cost = f[0];
            int city = f[1];
            int hop = f[2];
            if(city == dst) return cost;
            if(dist[city] < hop) continue;
            dist[city] = hop;
            if(hop > k) continue;
            for(auto i : adj[city]){
                pq.push({i.second+cost, i.first, hop+1});
            }
        }
        return -1;
    }
};
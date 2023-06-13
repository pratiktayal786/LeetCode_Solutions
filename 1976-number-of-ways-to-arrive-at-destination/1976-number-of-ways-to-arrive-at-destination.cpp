#define ll long long
#define pll pair<long, long>

class Solution {
public:
    int MOD = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pll> adj[n];
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        
        for(auto i : roads){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        
        while(!pq.empty()){
            auto [t, u] = pq.top();
            pq.pop();
            if(t > dist[u]) continue;
            for(auto [v, time] : adj[u]){
                if(time+t < dist[v]){
                    dist[v] = time+t;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if(time+t == dist[v]){
                    ways[v] = (ways[u]+ways[v])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};
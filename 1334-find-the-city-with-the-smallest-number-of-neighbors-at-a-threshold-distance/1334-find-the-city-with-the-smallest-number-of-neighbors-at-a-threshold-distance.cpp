class Solution {
public:
    
    using pii = pair<int,int>;
    int dijkstra(int src, vector<pii> adj[], int n, int thre){
        vector<int> dist(n, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int k = 0;
        
        pq.push({0,src});
        dist[src] = 0;
        
        while(!pq.empty()){
            auto [weight, city] = pq.top();
            pq.pop();
            
            if(dist[city] < weight) continue;
            
            for(auto [c, w] : adj[city]){
                if(dist[city]+w < dist[c]){
                    dist[c] = dist[city]+w;
                    pq.push({dist[c], c});
                }
            }
        }
        
        for(auto i : dist){
            if(i <= thre) k++;
        }
        
        return k;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pii> adj[n];
        vector<pii> ans;
        
        for(auto city : edges){
            adj[city[0]].push_back({city[1], city[2]});
            adj[city[1]].push_back({city[0], city[2]});
        }
        
        for(int i = 0; i < n; i++){
            ans.push_back({i, dijkstra(i, adj, n, distanceThreshold)});
        }
        
        sort(ans.begin(), ans.end(), [] (auto a, auto b){
           return a.second != b.second ? a.second < b.second : a.first > b.first; 
        });
        
        return ans[0].first;
    }
};












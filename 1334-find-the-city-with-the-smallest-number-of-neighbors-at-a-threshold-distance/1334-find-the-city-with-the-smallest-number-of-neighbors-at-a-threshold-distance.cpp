class Solution {
public:
    using pii = pair<int,int>; 
    int dijkstra(int src, vector<pii> adj[], int n, int thre){
        
        vector<int>  dist(n+1, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int k = 0;
        
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()){
            auto [weight, i] = pq.top();
            pq.pop();
            if(dist[i] < weight) continue;
            for(auto [j, w] : adj[i]){
                if(dist[i]+w < dist[j]){
                    dist[j] = dist[i]+w;
                    pq.push({w,j});
                }
            }
        }
        
        for(auto i : dist){
            if(i <= thre) k++;
        }
        return k;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pii> graph[n];
        vector<pii> ans;
        
        for(auto i : edges){
            graph[i[0]].push_back({i[1], i[2]});
            graph[i[1]].push_back({i[0], i[2]});
        }
        
        for(int i = 0; i < n; i++){
            ans.push_back({dijkstra(i, graph, n, distanceThreshold), i});
        }
        
        sort(ans.begin(), ans.end(), [] (auto a, auto b){
            return a.first != b.first ? a.first < b.first : a.second > b.second;
        });
        return ans[0].second;
    }
};
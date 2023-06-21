class Solution {
public:
    
    vector<int> parent;
    
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void dsUnion(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu != pv) parent[pv] = pu;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1) return -1;
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        
        for(auto i : connections){
            int u = i[0];
            int v = i[1];
            dsUnion(u, v);
        }
        
        int ans = 0; 
        for(int i = 0; i < n; i++){
            if(parent[i] == i) ans++;
        }
        return ans-1;
    }
};
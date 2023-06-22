class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    
    vector<int> parent;
    vector<int> size;
    
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void Union(int u, int v){
        int pu = find(u);
        int pv = find(v);
        parent[pv] = pu;
    }

    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        int n = stones.size();
        for(auto i : stones){
            maxRow = max(maxRow, i[0]);
            maxCol = max(maxCol, i[1]);
        }
        // DisjointSet ds(maxRow+maxCol+1);
        parent.resize(maxRow+maxCol+2);
        size.resize(maxRow+maxCol+2);
        for(int i = 0; i <= maxRow+maxCol+1; i++){
            parent[i] = i;
            size[i] = 1;
        }
        unordered_map<int,int> stoneNode;
        for(auto i : stones){
            int r = i[0];
            int c = i[1]+maxRow+1;
            Union(r, c);
            stoneNode[r] = 1;
            stoneNode[c] = 1;
        }
        int cnt = 0;
        for(auto i : stoneNode){
            if(find(i.first) == i.first) cnt++;
        }
        return n-cnt;
    }
};
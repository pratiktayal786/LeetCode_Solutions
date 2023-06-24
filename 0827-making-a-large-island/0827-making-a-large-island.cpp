class Solution
{
    public:

        vector<int> parent;
    vector<int> size;

    bool isValid(int r, int c, int n)
    {
        return r >= 0 && r < n && c >= 0 && c < n;
    }
    int find(int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unionBySize(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int largestIsland(vector<vector < int>> &grid)
    {

        int n = grid.size();
        parent.resize(n *n + 1);
        size.resize(n *n + 1);

        for (int i = 0; i <= n * n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }

        vector<pair<int, int>> moves = {
		{ 0,1 }, { 0,-1 }, { 1,0 },{ -1,0 }
        };

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if(grid[row][col] == 0) continue;
                    for (auto m: moves)
                    {
                        int newr = row + m.first;
                        int newc = col + m.second;
                        if (isValid(newr, newc, n) &&
                            (grid[newr][newc]))
                        {
                            int nodeNo = row*n + col;
                            int adjNodeNo =  newr *n + newc;
                            unionBySize(nodeNo,adjNodeNo);
                        }
                    }
            }
        }

        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) continue;
                unordered_set<int> st;
                for (auto m: moves)
                {
                    int r = i + m.first;
                    int c = j + m.second;
                    if (isValid(r, c, n) && grid[r][c] == 1)
                    {
                        st.insert(find(r *n + c));
                    }
                }
                int total = 0;
                for (auto s: st)
                {
                    total += size[s];
                }
                mx = max(mx, total + 1);
            }
        }

        for (int i = 0; i < n * n; i++)
        {
            mx = max(mx, size[find(i)]);
        }
        return mx;
    }
};
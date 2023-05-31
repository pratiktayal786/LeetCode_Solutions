class Solution
{
    public:
        vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int color)
        {

            queue<pair<int, int>> q;
            q.push({ sr,
                sc });
            int initial = image[sr][sc];
            image[sr][sc] = color;
            int n = image.size();
            int m = image[0].size();

            vector<pair<int, int>> dirs = {
		{ 1,
                    0 },
                { -1,
                    0 },
                { 0,
                    1 },
                { 0,
                    -1 }
            };

            while (!q.empty())
            {
                auto[x, y] = q.front();
                q.pop();
                for (auto[dx, dy]: dirs)
                {
                    int i = x + dx;
                    int j = y + dy;
                    if (i >= 0 && i < n && j >= 0 && j < m && image[i][j] == initial && image[i][j] != color)
                    {
                        image[i][j] = color;
                        q.push({ i,
                            j });
                    }
                }
            }
            return image;
        }
};
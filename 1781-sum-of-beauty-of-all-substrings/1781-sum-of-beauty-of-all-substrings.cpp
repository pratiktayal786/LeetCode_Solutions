class Solution
{
    public:
        int beautySum(string s)
        {

            int n = s.size();
            int ans = 0;

            for (int i = 0; i < n; i++)
            {

                vector<int> hash(26, 0);

                for (int j = i; j < n; j++)
                {

                    int maxy = INT_MIN;
                    int miny = INT_MAX;

                    hash[s[j] - 'a']++;

                    for (int i = 0; i < 26; i++)
                    {
                        if (hash[i] != 0)
                        {
                            maxy = max(maxy, hash[i]);
                            miny = min(miny, hash[i]);
                        }
                    }

                    if (miny == INT_MAX) miny = 0;
                    ans += (maxy - miny);
                }
            }
            return ans;
        }
};
class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {

            set<int> s;

            for (auto i: nums)
            {
                s.insert(i);
            }

            int n = nums.size();
            int maxStreak = 0;
            for (auto i: nums)
            {
                if (!s.count(i - 1))
                {
                    int curNum = i;
                    int curStreak = 1;
                    while (s.count(curNum + 1))
                    {
                        curStreak++;
                        curNum++;
                    }
                    maxStreak = max(maxStreak, curStreak);
                }
            }

            return maxStreak;
        }
};
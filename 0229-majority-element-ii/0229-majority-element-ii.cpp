class Solution
{
    public:
        vector<int> majorityElement(vector<int> &nums)
        {

            int n = nums.size();
            sort(nums.begin(), nums.end());
            int prev = nums[0];
            int count = 0;
            vector<int> ans;
            for (auto i: nums)
            {
                if (prev == i) count++;
                else
                {
                    if (count > (n / 3))
                    {
                        ans.push_back(prev);
                    }
                    prev = i;
                    count = 1;
                }
            }
            if (count > (n / 3))
            {
                ans.push_back(prev);
            }
            return ans;
        }
};
class Solution
{
    public:

        vector<vector < int>> threeSum(vector<int> &nums)
        {

            vector<vector<int>> ans;
            int n = nums.size();

            sort(nums.begin(), nums.end());

            for (int i = 0; i < n; i++)
            {

                int tar = -nums[i];
                int front = i + 1;
                int back = n - 1;

                while (front < back)
                {

                    int sum = nums[front] + nums[back];

                    if (sum == tar)
                    {
                        ans.push_back({ nums[i],
                            nums[front],
                            nums[back] });
                        while (front < back && nums[front] == nums[front + 1]) front++;
                        while (front < back && nums[back] == nums[back - 1]) back--;
                        front++;
                        back--;
                    }
                    else if (sum < tar) front++;
                    else back--;
                }
                while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                    i++;
            }
            return ans;
        }
};
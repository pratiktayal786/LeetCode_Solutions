class Solution
{
    public:
        vector<vector < int>> findMatrix(vector<int> &nums)
        {

            unordered_map<int, int> mp;
            for (auto i: nums) mp[i]++;

            vector<vector < int>> ans;

            while (mp.size())
            {

                vector<int> temp;
                for (auto i: mp) temp.push_back(i.first);
                for(auto i : temp){
                    if(!--mp[i]) mp.erase(i);
                }
                ans.push_back(temp);
            }
            return ans;
        }
};
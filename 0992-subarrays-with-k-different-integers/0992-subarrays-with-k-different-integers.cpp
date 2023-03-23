class Solution
{
    public:
        int subarraysWithKDistinct(vector<int> &nums, int k)
        {
            unordered_map<int,int> mp;
            int i = 0;
            int cnt = 0, prefix = 0;
            int ans = 0;
            
            for(int j = 0; j < nums.size(); j++){
                
                if(mp[nums[j]]++ == 0) cnt++;
                if(cnt > k) --mp[nums[i++]], --cnt, prefix = 0;
                while(mp[nums[i]] > 1) ++prefix, --mp[nums[i++]];
                if(cnt == k) ans += prefix+1;
            }
            return ans;
        }
};
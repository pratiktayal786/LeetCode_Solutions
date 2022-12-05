class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i+n/2] == nums[i]){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};
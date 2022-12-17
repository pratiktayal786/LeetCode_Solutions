class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int ans = nums[0];
        while(l <= r){
            int mid = (l+r)/2;
            ans = min(ans, nums[mid]);
            if(nums[l] <= nums[mid]){
                ans = min(ans, nums[l]);
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
    
};
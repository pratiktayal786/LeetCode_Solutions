class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int l = 0, r = n-1;
        int ans = 0;
        
        if(n == 1) return nums[0];
        while(l <= r){
            int mid = (l+r)/2;
            if(mid-1 >= 0 && nums[mid] == nums[mid-1]){
                if((mid-l+1)%2 == 0) l = mid+1;
                else r = mid-2;
            }
            else if(mid+1 < n && nums[mid] == nums[mid+1]){
                mid++;
                if((mid-l+1)%2 == 0) l = mid+1;
                else r = mid-2;
            }
            else {
                ans = nums[mid];
                break;
            }
        }
        return ans;
    }
};
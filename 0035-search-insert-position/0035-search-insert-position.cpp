class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
     
        int l = 0, r = nums.size()-1;
        
        while(l <= r){
            int mid = (l+r)/2;
            if(target == nums[mid]) return mid;
            else if(target > nums[mid]) l = mid+1;
            else r = mid-1;
        }
        if(l == -1) l = 0;
        return l;
    }
};
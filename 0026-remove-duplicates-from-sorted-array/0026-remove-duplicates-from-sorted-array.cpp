class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1, i = 0, j = 1, n = nums.size();
        
        while(i < n && j < n){
            if(nums[i] != nums[j]){
                swap(nums[i+1], nums[j]);
                i++;j++;k++;
            }
            else j++;
        }
        return k;
    }
};
class Solution {
public:
    
    int partition(vector<int> &nums, int left, int right){
        int pivot = nums[left];
        int l = left+1, r = right;
        
        while(l <= r){
            if(nums[l] < pivot && nums[r] > pivot) 
                swap(nums[l++],nums[r--]);
            if(nums[l] >= pivot) l++;
            if(nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
 
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l = 0, r = n-1, kth; 
        
        while(1){
            int ind = partition(nums, l, r);
            if(ind == k-1){
                kth = nums[ind];
                break;
            }
            else if(ind < k-1) l = ind+1;
            else r = ind-1;
        }
        return kth;
    }
    
};


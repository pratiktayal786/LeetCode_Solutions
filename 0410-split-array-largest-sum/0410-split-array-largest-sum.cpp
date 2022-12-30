class Solution {
public:
    
    bool check(vector<int> &arr, int k, int mid){
        
        int c = 0;
        int sum = 0;
        for(int i = 0; i < arr.size(); i++){
            if(sum+arr[i] <= mid){
                sum += arr[i];
            }
            else{
                sum = arr[i];
                c++;
            }
        }
        c++;
        if(c > k) return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int l = *max_element(nums.begin(), nums.end());
        int r = 0;
        for(auto i : nums) r += i;
        
        if(k == nums.size()) return l;
        
        while(l <= r){
            int mid = (l+r)/2;
             
            if(check(nums, k, mid)) r = mid-1;
            else l = mid+1;
        }
        return l;
    }
};
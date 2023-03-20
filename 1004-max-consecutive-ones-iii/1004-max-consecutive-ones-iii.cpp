class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int start = 0, n = nums.size(), cnt0 = 0, ans = INT_MIN;
        
        for(int end = 0; end < n; end++){
            if(nums[end] == 0) cnt0++;
            
            while(cnt0 > k){
                if(nums[start] == 0) cnt0--;
                start++;
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
    
    int solve(vector<int> &nums, int k){
        int i = 0, ans = 0, cnt = 0;
        
        for(int j = 0; j < nums.size(); j++){
            
            if(nums[j] & 1) cnt++;
            while(cnt > k){
                if(nums[i]&1) cnt--;
                i++;
            }
            ans += (j-i+1);
        }
        return ans;
    }
};
class Solution {
public:
    
    int solve(vector<int> &nums, int goal){
        
        if(goal < 0) return 0;
        
        int sum = 0;
        int i = 0;
        int ans = 0;
        for(int j = 0; j < nums.size(); j++){
            
            sum += nums[j];
            while(sum > goal) sum -= nums[i++];
            ans += (j-i+1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return solve(nums, goal) - solve(nums, goal-1);
    }
};
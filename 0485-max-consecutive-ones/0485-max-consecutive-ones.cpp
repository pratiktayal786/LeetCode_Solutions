class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxy = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            maxy = max(maxy, sum);
            if(nums[i] == 0) sum = 0;
        }
        return maxy;
    }
};
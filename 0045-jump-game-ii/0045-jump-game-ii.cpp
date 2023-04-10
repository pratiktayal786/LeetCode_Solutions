class Solution {
public:
    int jump(vector<int>& nums) {
        
        int curReach = 0, maxReach = 0, jump = 0;
        
        for(int i = 0; i < nums.size()-1; i++){
            
            maxReach = max(maxReach, i+nums[i]);
            if(i == curReach){
                jump++;
                curReach = maxReach;
            }
        }
        return jump;
    }
};
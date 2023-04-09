class Solution {
public:
    
    
    bool solve(int i, vector<int> &nums, vector<int> &mem){
        if(i == nums.size()-1) return true;
        
        if(mem[i] != -1) return mem[i];
        
        int reach = i+nums[i];
        for(int j = i+1; j <= reach; j++){
            if(solve(j, nums, mem)) return mem[i] = true;
        }
        return mem[i] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> mem(n, -1);
        return solve(0, nums, mem);
    }
};
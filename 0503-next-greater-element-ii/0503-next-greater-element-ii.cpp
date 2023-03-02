class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;
        
        for(int i = 0; i < 2*n; i++){
            
            while(stk.size() && nums[stk.top()] < nums[i%n]){
                res[stk.top()] = nums[i%n];
                stk.pop();
            }
            stk.push(i%n);
        }
        return res;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int res = 0;
        stack<int> stk;
        int i = 0;
        
        while(i < n){
            if(stk.empty() || height[i] <= height[stk.top()]) stk.push(i++);
            else{
                int topN = stk.top();
                stk.pop();
                res += stk.empty() ? 0 : (min(height[stk.top()], height[i])-height[topN])*(i-stk.top()-1);
            }
        }
        return res;
    }
};
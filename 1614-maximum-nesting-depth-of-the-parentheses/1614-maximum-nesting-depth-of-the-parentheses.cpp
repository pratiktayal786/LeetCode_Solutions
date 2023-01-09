class Solution {
public:
    int maxDepth(string s) {
        
        stack<char> stk;
        
        int maxCount = 0;
        
        for(auto i : s){
            if(i == '('){
                stk.push('(');
            }
            else if(i == ')'){
                maxCount = max(maxCount, (int)stk.size());
                stk.pop();
            }
        }
        return maxCount;
    }
};
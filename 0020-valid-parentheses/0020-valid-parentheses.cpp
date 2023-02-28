class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;
        
        for(auto i : s){
            if(i == '(' || i == '[' || i == '{'){
                stk.push(i);
            }
            else if(!stk.empty()){
                if(i == ')' && stk.top() == '('){
                    stk.pop();
                }
                
                else if(i == ']' && stk.top() == '['){
                    stk.pop();
                }
                
                else if(i == '}' && stk.top() == '{'){
                    stk.pop();
                }
                
                else{
                    return false;
                }
            }
            else return false;
        }
        
        return stk.empty();
    }
};
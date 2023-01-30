class Solution {
public:
    
    void solve(string str, int lp, int rp, vector<string> &ans){
        
        if(lp == 0 && rp != 0){
            while(rp--){
                str.push_back(')');
            }
        }
        if(lp <= 0 && rp <= 0){
            ans.push_back(str);
            return;
        }
        if((lp != 0 && rp <= 0) || (lp > rp)){
            return;
        }
        str.push_back('(');
        solve(str, lp-1, rp, ans);
        str.pop_back();
        str.push_back(')');
        solve(str, lp, rp-1, ans);
        str.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        
        if(n == 0) return {""};
        vector<string> ans;
        solve("(", n-1, n, ans);
        return ans;
    }
};
class Solution {
public:
    
    void solve(string str, int lp, int rp, vector<string> &ans){
      
        if(lp == 0 && rp == 0){
            ans.push_back(str);
            return;
        }
        
        if(lp > 0) solve(str+"(", lp-1, rp+1, ans);
        if(rp > 0) solve(str+")", lp, rp-1, ans);
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        solve("", n, 0, ans);
        return ans;
    }
};
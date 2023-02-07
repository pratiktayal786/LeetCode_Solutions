class Solution {
public:
    
    unordered_map<string, bool> dp;
    bool solve(string s, unordered_set<string> &map){
        
        if(s.length() == 0) return true;
        if(dp.find(s) != dp.end()) return dp[s];
        
        for(int i = 1; i <= s.size(); i++){
            if(map.count(s.substr(0,i)) && solve(s.substr(i), map)) {
                dp[s] = true;
                return true;
            }
            else dp[s] = false;
        }
         return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> map;
        map.insert(wordDict.begin(), wordDict.end());
        return solve(s, map);
    }
};
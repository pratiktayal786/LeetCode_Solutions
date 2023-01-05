class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int minLen = INT_MAX;
        
        string ans = "";
        
        for(auto i : strs){
            minLen = min(minLen, (int)i.size());
        }
        
        int i = 0;
        int n = strs.size();
        
        while(i < minLen){
            char c = strs[0][i];
            int cnt = 0;
            
            for(int j = 0; j < n; j++){
                if(strs[j][i] == c) ++cnt;
            }
            
            if(cnt == n) ans += c;
            else return ans;
            i++;
        }
        return ans;
    }
};
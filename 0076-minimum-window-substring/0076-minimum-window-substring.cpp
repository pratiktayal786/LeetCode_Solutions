class Solution {
public:
    string minWindow(string s, string t) {
        
        int i = 0, n = t.length(), head = 0, anslen = INT_MAX;
        unordered_map<char, int> mp;
        for(auto c : t) mp[c]++;
        
        for(int j = 0; j < s.length(); j++){
            
            if(mp[s[j]]-- > 0) --n;
            while(n == 0){
                if(anslen > (j-i+1)) anslen = (j-(head=i)+1);
                if(mp[s[i++]]++ == 0) ++n;
            }
        }
        return  anslen == INT_MAX ? "" : s.substr(head, anslen);              
    }
};
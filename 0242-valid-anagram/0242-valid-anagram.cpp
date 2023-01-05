class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int alpha1[26] = {0};
        int alpha2[26] = {0};
        
        if(s.size() != t.size()) return false;
        
        for(int i = 0; i < s.size(); i++){
            alpha1[s[i]-'a']++;
            alpha2[t[i]-'a']++;
        }
        
        for(int i = 0; i <26; i++){
            if(alpha1[i] != alpha2[i]) return false;
        }
        return true;
    }
};
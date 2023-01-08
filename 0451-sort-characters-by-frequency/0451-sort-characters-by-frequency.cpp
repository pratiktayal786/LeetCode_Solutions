class Solution {
public:
    string frequencySort(string s) {
        
        int n = s.size();
        int hash[256] = {0};
        for(auto i : s) hash[i]++;
        sort(s.begin(), s.end(), [&](char a, char b){
            return hash[a] > hash[b] || (hash[a] == hash[b] && a < b);
        });
        return s;
    }
};
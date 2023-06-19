class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxGain = 0;
        int n = gain.size();
        int ans = 0;
        
        for(auto i : gain){
            maxGain += i;
            ans = max(ans, maxGain);
        }
        return ans;
    }
};
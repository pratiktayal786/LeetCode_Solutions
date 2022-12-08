class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> s;
        for(auto i : nums){
            s.insert(i);
        }
        int maxy = 0;
        for(auto i : nums){
            if(!s.count(i-1)){
                int curNum = i;
                int count = 1;
                while(s.count(curNum+1)){
                    curNum++;
                    count++;
                }
                maxy = max(maxy, count);
            }
        }
        return maxy;
    }
};
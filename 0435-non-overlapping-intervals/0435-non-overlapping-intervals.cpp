class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        int inter = intervals[0][1];
        int count = 0;
        
        for(int i = 1; i < intervals.size(); i++){
            
            if(intervals[i][0] < inter){
                count++;
                inter = min(inter, intervals[i][1]);
            }
            else{
                inter = intervals[i][1];
            }
        }
        return count;
    }
};
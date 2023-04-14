class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> inter = {intervals[0][0], intervals[0][1]};
        
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][1] < inter[0]) ans.push_back(intervals[i]);
            else if(intervals[i][0] > inter[1]){
                ans.push_back(inter);
                inter = intervals[i];
            }
            else if(intervals[i][0] <= inter[1] || intervals[i][1] <= inter[0]){
                inter[0] = min(inter[0], intervals[i][0]);
                inter[1] = max(inter[1], intervals[i][1]);
            }
        }
        ans.push_back(inter);
        return ans;
    }
};
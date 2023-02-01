class Solution {
public:
    
    void solve(vector<int> &can, int tar, int ind, vector<int> ds, vector<vector<int>> &ans){
        
        if(tar == 0){
            ans.push_back(ds);
            return;
        }
        else{
            for(int i = ind; i < can.size(); i++){
                
                if(can[i] <= tar) {
                    ds.push_back(can[i]);
                    solve(can, tar-can[i], i+1, ds, ans);
                    ds.pop_back();
                }
                while(i+1 < can.size() && can[i] == can[i+1]) i++;
            }
        }  
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        solve(candidates, target, 0, ds, ans);
        return ans;
    }
};
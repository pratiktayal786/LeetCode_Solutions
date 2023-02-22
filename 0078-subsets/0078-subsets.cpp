class Solution {
public:
    
    void getSubSets(vector<vector<int>> &res, vector<int> &nums, int i){
        
        vector<int> v;
        int j = 0;
        
        while(i > 0){
            if((i & 1) == 1) v.push_back(nums[j]);
            i = i >> 1;
            j++;
        }
        res.push_back(v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        
        int n = nums.size();
        
        for(int i = 0; i < (1 << n); i++){
            getSubSets(res, nums, i);
        }
        
        return res;
    }
};
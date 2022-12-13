class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int promin = nums[0], promax = nums[0], result = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            int temp = max({nums[i], promin*nums[i], promax*nums[i]});
            promin = min({nums[i], promin*nums[i], promax*nums[i]});
            promax = temp;
            
            result = max(result, promax);
        }
        return result;
    }
};
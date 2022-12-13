class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int maxleft = nums[0], maxright = nums[n-1];
        
        int prod = 1, zeropresent = 0;
        
        for(int i = 0; i < n; i++){
            prod *= nums[i];
            if(prod == 0){
                zeropresent = 1;
                prod = 1;
                continue;
            }
            maxleft = max(maxleft, prod);
        }
        
        prod = 1;
        for(int j = n-1; j >= 0; j--){
            prod *= nums[j];
            if(prod == 0){
                zeropresent = 1;
                prod = 1;
                continue;
            }
            maxright = max(maxright, prod);
        }
        if(zeropresent) return max(max(maxleft, maxright), 0);
        return max(maxleft, maxright);
    }
};
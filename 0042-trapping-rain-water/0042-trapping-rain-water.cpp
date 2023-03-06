class Solution {
public:
    int trap(vector<int>& height) {
        
        int leftmax = 0, rightmax = 0;
        int l = 0, r = height.size()-1;
        int ans = 0;
        
        while(l <= r){
            
            if(height[l] <= height[r]){
                if(height[l] >= leftmax) leftmax = height[l];
                else ans += leftmax-height[l];
                l++;
            }
            else{
                if(height[r] >= rightmax) rightmax = height[r];
                else ans += rightmax-height[r];
                r--;
            }
        }
        return ans;
    }
};
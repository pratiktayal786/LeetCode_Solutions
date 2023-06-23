class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        vector<int> nums;
        while(x){
            nums.push_back(x%10);
            x /= 10;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != nums[nums.size()-i-1]) return false;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> mp;
        int n = nums2.size();
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            mp[nums2[i]] = i;
        }
        
        for(auto i : nums1){
            int ind = mp[i];
            int flag = 0;
            
            while(ind+1 < n){
                if(nums2[ind+1] > i) {
                    ans.push_back(nums2[++ind]);
                    flag = 1;
                    break;
                }
                ind++;
            }
            if(flag == 0) ans.push_back(-1);
        }
        return ans;
    }
};
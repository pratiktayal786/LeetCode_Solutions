class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        if(k > nums.size()) return -1;
        priority_queue<int> q;
        
        for(auto i : nums) q.push(i);
        
        while(k-- > 1) q.pop();
    
        return q.top();
    }
    
};
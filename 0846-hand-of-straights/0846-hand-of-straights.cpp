class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        unordered_map<int,int> mp;
        for(auto i : hand) mp[i]++;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto i : mp) pq.push(i.first);
        
        while(!pq.empty()){
            
            if(pq.size() < groupSize) return false;
            
            vector<int> temp;
            int prev = 0;
            temp.push_back(prev = pq.top());
            pq.pop();
            
            for(int i = 1; i < groupSize; i++){
                if(pq.top() == prev+1) {
                    temp.push_back(pq.top());
                    prev = pq.top();
                    pq.pop();
                }
                else return false;
            }
            
            for(auto i : temp){
                if(--mp[i] > 0) pq.push(i);
            }
            
        }
        return true;
    }
};
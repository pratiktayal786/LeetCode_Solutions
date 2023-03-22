class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int i = 0, n = cardPoints.size(), len = n-k-1;
        int total = accumulate(cardPoints.begin(),cardPoints.end(), 0);
        int sum = 0, ans = 0;
        
        if(k == n) return total;
        for(int j = 0; j < n; j++){
            sum += cardPoints[j];
            if(len == j-i){
                ans = max(ans, total-sum);
                sum -= cardPoints[i++];
            }
        }
        return ans;
    }
};
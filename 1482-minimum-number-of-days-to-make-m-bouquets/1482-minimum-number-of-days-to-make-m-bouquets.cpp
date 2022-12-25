class Solution {
public:
    
    bool checking(vector<int> &arr, int m, int k, int mid){
        
        int cnt = 0;
        int x = 0;
        
        for(int i = 0; i < arr.size(); i++){
            
            if(arr[i] <= mid) cnt++;
            else cnt = 0;
            if(cnt == k) {
                x++;
                cnt = 0;
            }
            if(x == m) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        if(n < m || n < m*k) return -1;
        
        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(l <= r){
            int mid = (l+r)/2;
            
            bool check = checking(bloomDay, m, k, mid);
            
            if(check) r = mid-1;
            else l = mid+1;
        }
        return l;
    }
};
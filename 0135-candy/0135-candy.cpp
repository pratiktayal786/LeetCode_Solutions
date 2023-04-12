class Solution {
public:
    int candy(vector<int>& r) {
        
        int len = r.size();
        int res = 0;
        
        if(len > 0){
            vector<int> number(len, 0);
            number[0] = 1;
            
            for(int i = 1; i < len; i++){
                number[i] = r[i] > r[i-1] ? number[i-1]+1 : 1;
            }
            
            res = number[len-1];
            for(int i = len-2; i >= 0; i--){
                if(r[i] > r[i+1] && (number[i] < (number[i+1]+1))) 
                    number[i] = number[i+1]+1;
                res += number[i];
            }
        }
        return res;
    }
};
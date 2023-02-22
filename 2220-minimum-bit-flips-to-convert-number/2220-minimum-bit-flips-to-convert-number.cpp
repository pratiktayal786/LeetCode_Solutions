class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int count = 0;
        
        for(int i = 0; i < sizeof(int)*8; i++){
            
            if((goal & (1 << i)) && (start & (1 << i)) ||
               (!(goal & (1 << i)) && !(start & (1 << i)))) continue;
            count++;
        }
        
        return count;
    }
};
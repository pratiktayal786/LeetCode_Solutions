class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        long dvd = labs(dividend), dvs = labs(divisor);
        int sign = dividend>0 ^ divisor>0 ? -1 : 1;
        long ans = 0;
        
        while(dvs <= dvd){
            long m = 1;
            long temp = dvs;
            while(temp << 1 <= dvd){
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign*ans;
    }
};
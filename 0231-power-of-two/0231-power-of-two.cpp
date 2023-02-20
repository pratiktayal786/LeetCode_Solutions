class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0) return false;
        
        int total = log2(abs(n))+1;
        
        total = ~(1 << (total-1));
        return (n & total) == 0; 
    }
};
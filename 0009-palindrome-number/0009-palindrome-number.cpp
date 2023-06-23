class Solution {
public:
    bool isPalindrome(int x) {
        
        int y = x;
        if(x < 0) return false;
        int rem = 0;
        long long rev = 0;
        while(x){
            rem = x%10;
            rev = rev*10 + rem;
            x /= 10;
        }
        return y == rev;
    }
};
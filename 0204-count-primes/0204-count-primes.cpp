class Solution {
public:
    int countPrimes(int n) {
       
        if(n < 2) return 0;
        
        vector<bool> primes(n, true);
        int count = 0;
        
        for(int i = 2; i < n;  i++){
            
            if(primes[i]) count++;
            if(i > sqrt(n)) continue;
            for(int j = i*i; j < n; j += i){
                primes[j] = false;
            }
        }
        return count;
    }
};
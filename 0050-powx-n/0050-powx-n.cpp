class Solution {
public:
    
    double solve(double x, int n){
        if(n <= 0) return 1.0; 
        
        if(n%2){
            return (double)x * (double)solve(x, n-1);
        }
        return (double)solve(x*x, n/2);
    }
    double myPow(double x, int n) {
        int nn = n;
        if(nn < 0) nn = (nn == INT_MIN) ? INT_MAX : nn*(-1);
        double ans = solve(x, nn);
        if(n < 0 && x < 0 && n%2==0) return (double)-1.0/(double)ans;
        else if(n < 0) return (double)1.0/(double)ans;
        return ans;
    }
};
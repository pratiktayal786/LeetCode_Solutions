//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:

    int dp[25][200];
    int solve(int i, int xr, int k, vector<int> &arr, int n){
        if(i == n){
            if(xr == k) return 1;
            return 0;
        }
        
        if(dp[i][xr] != -1) return dp[i][xr];
        
        int ans = 0;
        int a1 = solve(i+1, xr^arr[i], k, arr, n);
        int a2 = solve(i+1, xr, k, arr, n);
        ans = a1+a2;
        return dp[i][xr] = ans;
    }
    int subsetXOR(vector<int> arr, int n, int k) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, k, arr, n);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends
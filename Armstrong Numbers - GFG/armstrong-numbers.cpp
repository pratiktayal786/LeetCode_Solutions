//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        int temp = n;
        int count = 0;
        while(temp > 0){
            temp /= 10;
            count++;
        }
        temp = n;
        int ans = 0;
        while(temp > 0){
            int val = temp%10;
            ans += pow(val, count);
            temp /= 10;
        }
        if(ans == n) return "Yes";
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
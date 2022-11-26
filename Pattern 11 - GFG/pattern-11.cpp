//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        string str = "";
        
        for(int i = 1; i <= n; i++){
            
                if(i%2 != 0){
                    str = "1 " + str;
                    cout <<str;
                }
                else{
                    str = "0 " + str;
                    cout <<str;
                }

            cout <<endl;
        }
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
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends
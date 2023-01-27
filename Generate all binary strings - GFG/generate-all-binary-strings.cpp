//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void solve(int num, string ans){
        
        if(num == 0){
            cout <<ans<<" ";
            return;
        }
        solve(num-1, ans+"0");
        if(ans == "" || ans[ans.size()-1] == '0') solve(num-1, ans+"1");
    }
    void generateBinaryStrings(int& num){
        //Write your code
        
        solve(num, "");
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        // cout << setprecision(9) << obj.switchCase(choice,vec) << endl;
        obj.generateBinaryStrings(n);
        cout << endl;
        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
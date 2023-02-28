//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  bool isoperator(char c){
      if(!isalpha(c) && !isdigit(c)) return true;
      return false;
  }
    string preToPost(string exp) {
        stack<string> stk;
        string res;
        int n = exp.size();
        for(int i = n-1; i >= 0; i--){
            if(isoperator(exp[i])){
                 string x = stk.top();
                 stk.pop();
                 string y = stk.top();
                 stk.pop();
                 x = x+y+exp[i];
                 stk.push(x);
            }
            else{
                stk.push(string(1, exp[i]));
            }
        }
        return stk.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
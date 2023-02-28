//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string exp) {
        // Write your code here
        stack<char> stk;
        string res;
        
        for(auto i : exp){
            if(!isalpha(i) && !isdigit(i)){
                res.push_back('(');
                stk.push(')');
                stk.push(i);
            }
            else{
                res.push_back(i);
                while(!stk.empty() && stk.top() == ')'){
                    res.push_back(')');
                    stk.pop();
                }
                if(!stk.empty()) res.push_back(stk.top());
                stk.pop();
            }
        }
        
        return res;
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
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
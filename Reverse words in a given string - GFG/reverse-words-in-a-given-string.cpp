//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        reverse(S.begin(), S.end());
        S += '.';
        
        int l = 0, r = 0;
        int n = S.size();
        
        while(r < n){
            if(r < n && S[r] != '.') r++;
            else{
                reverse(S.begin()+l, S.begin()+r);
                l = ++r;
            }
        }
        S.pop_back();
        
        return S;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
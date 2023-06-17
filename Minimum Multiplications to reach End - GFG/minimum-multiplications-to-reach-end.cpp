//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start == end) return 0;
        int vis[100001] = {0};
        int ans = 1;
        queue<int> q;
        
        q.push(start);
        vis[start] = 1;
        
        while(!q.empty()){
            int s = q.size();
            
            while(s--){
                int v = q.front();
                q.pop();
                for(auto i : arr){
                    int x = (v*i)%100000;
                    if(x == end) return ans;
                    if(!vis[x]){
                        vis[x] = 1;
                        q.push(x);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
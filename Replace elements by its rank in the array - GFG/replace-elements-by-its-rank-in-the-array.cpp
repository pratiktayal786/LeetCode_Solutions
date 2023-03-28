//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#define pii pair<int,int>
class Solution{
public:
    class Comp{
        public: 
        bool operator()(pii &x, pii &y){
            return x.first < y.first;
        }
    };

    vector<int> replaceWithRank(vector<int> &arr, int N){
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        for(int i = 0; i < N; i++){
            pq.push({arr[i], i});
        }
        
        int rank = 0;
        int prev = -1;
        
        while(!pq.empty()){
            
            if(prev == pq.top().first) arr[pq.top().second] = rank;
            else{
                arr[pq.top().second] = ++rank;
            }
            prev = pq.top().first;
            pq.pop();
        }
        return arr;
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
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
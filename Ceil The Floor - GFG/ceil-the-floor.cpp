//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    
    int l = 0, r = n-1;
    sort(arr, arr+n);
    
    while(l <= r){
        int mid = (l+r)/2;
        if(arr[mid] > x) r = mid-1;
        else if(arr[mid] < x) l = mid+1;
        else return {arr[mid], arr[mid]};
    }
    if(l >= n) return {arr[r], -1};
    else if(r < 0) return {-1, arr[l]};
    return {arr[r], arr[l]};
}
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
#define lli long long int

class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here 
        lli l = 0, r = x;
        
        while(l <= r){
            lli mid = (l+r)/2;
            lli sq = mid*mid;
            
            if(sq == x) return mid;
            else if(sq > x) r = mid-1;
            else l = mid+1;
        }
        return r;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends
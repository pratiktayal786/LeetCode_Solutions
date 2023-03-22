class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int i = 0, n = s.length(), ans = 0;
        int arr[3] = {0};
        
        for(int j = 0; j < n; j++){
            arr[s[j]-'a']++;            
            while(arr[0] >= 1 && arr[1] >= 1 && arr[2] >= 1){
                ans += (n-j);
                arr[s[i++]-'a']--;
            }
        }
        return ans;
    }
};
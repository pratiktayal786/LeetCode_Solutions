class Solution {
public:
    int romanToInt(string s) {
        
        int i = 0;
        int n = s.size();
        int ans = 0;
        
        while(i < n){
            char t = s[i];
            
            if(t == 'M') ans += 1000;
            else if(t == 'D') ans += 500;
            else if(t == 'L') ans += 50;
            else if(t == 'V') ans += 5;
            else if(t == 'I'){
                if( i < n-1 && s[i+1] == 'V') ++i,ans += 4;
                else if( i < n-1 && s[i+1] == 'X') ++i,ans += 9;
                else ans += 1;
            }
            else if(t == 'X'){
                if(i < n-1 && s[i+1] == 'L') ++i,ans += 40;
                else if(i < n-1 && s[i+1] == 'C') ++i,ans += 90;
                else ans += 10;
            }
            else if(t == 'C'){
                if(i < n-1 && s[i+1] == 'D') ++i,ans += 400;
                else if(i < n-1 && s[i+1] == 'M') ++i,ans += 900;
                else ans += 100;
            }
            i++;
        }
        return ans;
    }
};
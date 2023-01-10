class Solution
{
    public:
        int myAtoi(string s)
        {

            int ind = 0;
            int n = s.size();
            int sign = 1;
            int ans = 0;

            while (ind < n && s[ind] == ' ') ind++;

            if (ind < n)
            {
                if (s[ind] == '-')
                {
                    sign = -1;
                    ind++;
                }
                else if (s[ind] == '+')
                { 
                    ind++;
                }
            }

            while(ind < n && s[ind] >= '0' && s[ind] <= '9'){
                
                int digit = s[ind]-'0';
                
                if(ans > (INT_MAX/10) || (ans == (INT_MAX/10) && digit > 7)){
                    return sign==1 ? INT_MAX : INT_MIN;
                }
                ans = ans*10 + digit;
                ind++;
            }
            return ans*sign;
        }
};
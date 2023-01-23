class Solution
{
    public:

        void solve(string str, int ind, int &ans, int &sign)
        {

            char ch = str[ind];
            if (!isdigit(ch) || ind == str.size()) return;
            else if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && ch > '7'))
            {
                ans = sign == 1 ? INT_MIN : INT_MAX;
                return;
            }

            int digit = ch - '0';
            ans = ans *10 + digit;
            solve(str, ind + 1, ans, sign);
        }

    int myAtoi(string s)
    {

        int ans = 0;
        int ind = 0;
        int sign = 0;
        if (ind < s.size())
        {
            while (s[ind] == ' ') ++ind;
            if (s[ind] == '-')
            {
                sign = 1;
                ++ind;
            }
            else if (s[ind] == '+')
            {
                ++ind;
            }
        }

        solve(s, ind, ans, sign);
        if (sign)
        {
            if (ans == INT_MIN) return INT_MIN;
            else return ans *(-1);
        }
        return ans;
    }
};
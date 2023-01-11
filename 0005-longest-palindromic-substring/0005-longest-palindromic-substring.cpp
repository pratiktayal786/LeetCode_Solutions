class Solution
{
    public:

        void palindrome(string &str, int s, int e, int &ind, int &len)
        {
            while (s >= 0 && e < str.size())
            {
                if (str[s] != str[e]) return;
                else
                {
                    if (e - s + 1 >= len)
                    {
                        len = e - s + 1;
                        ind = s;
                    }
                }
                s--;
                e++;
            }
        }
    
    string longestPalindrome(string s)
    {

        int size = 0;	// it will store max length of palindrome string
        int index = -1;	// it will store index of palindrome string
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
        	palindrome(s, i, i, index, size);
            palindrome(s, i, i+1, index, size);
        }
        return s.substr(index, size);	// making ans string from index and size
    }
};
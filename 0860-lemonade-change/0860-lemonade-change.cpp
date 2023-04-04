class Solution
{
    public:
        bool lemonadeChange(vector<int> &bills)
        {

            int n5 = 0, n10 = 0;

            for (int i = 0; i < bills.size(); i++)
            {

                if (bills[i] == 5)
                {
                    n5++;
                }
                else if (bills[i] == 10 && n5 >= 1)
                {
                    n5--;
                    n10++;
                }
                else if (bills[i] == 20 && n10 >= 1 && n5 >= 1)
                {
                    n5--;
                    n10--;
                }
                else if(bills[i] == 20 && n5 >= 3){
                    n5 -= 3;
                }
                else return false;
            }
            return true;
        }
};
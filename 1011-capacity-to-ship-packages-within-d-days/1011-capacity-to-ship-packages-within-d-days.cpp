class Solution
{
    public:

        bool checking(vector<int> &arr, int days, int mid)
        {

            int count = 1;
            int total = 0;

            for (int i = 0; i < arr.size(); i++)
            {
                total += arr[i];
                if(total > mid){
                    count++;
                    total = arr[i];
                }
            }
            return count <= days;
        }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int l = *max_element(weights.begin(), weights.end()), r = 0;
        
        for(auto i : weights) r += i;
        
        while (l < r)
        {
            int mid = (l + r) / 2;        
            bool check = checking(weights, days, mid);
            if (check) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
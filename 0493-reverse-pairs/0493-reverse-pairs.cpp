class Solution
{
    public:
    
    int ans = 0;
    
        void MergeSortedIntervals(vector<int> &v, int s, int m, int e)
        {

            int x = m + 1;

            for (int i = s; i <= m; i++)
            {
                while (x <= e && v[i] > 2LL *v[x])
                {
                    ++x;
                }

                ans += (x - (m + 1));
            }

           	// temp is used to temporary store the vector obtained by merging
           	// elements from[s to m] and[m+1 to e] in v
            vector<int> temp;

            int i, j;
            i = s;
            j = m + 1;

            while (i <= m && j <= e)
            {

                if (v[i] <= v[j])
                {
                    temp.push_back(v[i]);
                    ++i;
                }
                else
                {
                    temp.push_back(v[j]);
                    ++j;
                }
            }

            while (i <= m)
            {
                temp.push_back(v[i]);
                ++i;
            }

            while (j <= e)
            {
                temp.push_back(v[j]);
                ++j;
            }

            for (int i = s; i <= e; ++i)
                v[i] = temp[i - s];
        }

   	// the MergeSort function
   	// Sorts the array in the range[s to e] in v using
   	// merge sort algorithm
    void MergeSort(vector<int> &v, int s, int e)
    {
        if (s >= e) return;

        int m = (s + e) / 2;
        MergeSort(v, s, m);
        MergeSort(v, m + 1, e);
        MergeSortedIntervals(v, s, m, e);
    }

    int reversePairs(vector<int> &nums)
    {
         MergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
};
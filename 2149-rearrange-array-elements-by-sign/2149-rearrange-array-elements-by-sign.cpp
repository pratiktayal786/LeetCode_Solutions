class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> newArr(n, 0);
        int a = 0, b = 1;
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                newArr[a] = arr[i];
                a += 2;
            }
            else{
                newArr[b] = arr[i];
                b += 2;
            }
        }
        return newArr;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        
        vector<int> v1, v2;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(arr[i] > 0) v1.push_back(arr[i]);
            else v2.push_back(arr[i]);
        }
        int a = 0, b = 0;
        for(int i = 0; i < n; i++){
            if(i%2 == 0){
                arr[i] = v1[a++];
            }
            else{
                arr[i] = v2[b++];
            }
        }
        return arr;
    }
};
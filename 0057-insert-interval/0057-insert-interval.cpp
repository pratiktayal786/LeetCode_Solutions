class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newArr) {
        
        vector<vector<int>> ans;
        
       
        for(int i = 0; i < arr.size(); i++){
            
            if(arr[i][1] < newArr[0]){
                ans.push_back(arr[i]);
            }
            else if(arr[i][0] > newArr[1]){
                ans.push_back(newArr);
                newArr = arr[i];
            }
            else if(arr[i][0] <= newArr[1] || arr[i][1] <= newArr[1]){
                newArr[0] = min(newArr[0], arr[i][0]);
                newArr[1] = max(newArr[1], arr[i][1]);
            }
        }
        ans.push_back(newArr);
        return ans;
    }
};
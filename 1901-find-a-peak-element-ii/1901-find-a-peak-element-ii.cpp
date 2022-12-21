class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int startCol = 0; int endCol = mat[0].size()-1;
        
        while(startCol <= endCol){
            int midCol = (startCol+endCol)/2;
            int maxRow = 0;
            
            for(int row = 0; row < n; row++){
                maxRow = mat[row][midCol] >= mat[maxRow][midCol] ? row : maxRow;
            }
            
            bool leftIsBig = (midCol-1 > startCol &&
                              mat[maxRow][midCol-1] > mat[maxRow][midCol]) 
                                ? true : false;
            bool rightIsBig = (midCol+1 <= endCol &&
                              mat[maxRow][midCol+1] > mat[maxRow][midCol]) 
                                ? true : false;
            if(!leftIsBig && !rightIsBig) return {maxRow, midCol};
            else if(leftIsBig) endCol = midCol-1;
            else startCol = midCol+1;
        }
        return {-1,-1};
    }
};
class Solution {
public:
    
    bool isValid(int r, int c, vector<vector<char>>& board){
        int val = board[r][c];
        
        for(int i = 0; i < 9; i++){
            if(i != c && board[r][i] == val) return false;
        }
        
        for(int i = 0; i < 9; i++){
            if(i != r && board[i][c] == val) return false;
        }
        
        for(int i = 0; i < 9; i++){
            int row = 3*(r/3) + (i/3);
            int col = 3*(c/3) + (i%3);
            if(row != r && col != c && board[row][col] == val) return false;
        }
        
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && !isValid(i, j, board)) return false; 
            }
        }
        return true;
    }
};
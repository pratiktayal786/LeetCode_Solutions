class Solution {
public:
    
    bool isValid(int r, int c, vector<vector<char>> &board, char ch){
        
        for(int row = 0; row < 9; row++) 
            if(board[row][c] == ch) return false;
        for(int col = 0; col < 9; col++)
            if(board[r][col] == ch) return false;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[3*(r/3) + i][3*(c/3) + j] == ch) return false;
            }
        }
        return true;
    }
    bool solve(int r, int c, vector<vector<char>> &board){
        
        if(r == board.size()) return true;
        if(c == board[r].size()) return solve(r+1, 0, board);
        if(board[r][c] != '.') return solve(r, c+1, board);
        
        for(char ch = '1'; ch <= '9'; ch++){
            if(isValid(r, c, board, ch)){
                board[r][c] = ch;
                if(solve(r, c+1, board)) return true;
                board[r][c] = '.';
            }
        }
        
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, board);
    }
};
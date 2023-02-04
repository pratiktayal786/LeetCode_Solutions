class Solution {
public:
    
    bool dfs(vector<vector<char>> &board, int i, int j, int ind, string word){
        
        if(ind == word.size()) return true;
        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[ind]) return false;
        
        char c = board[i][j];
        board[i][j] = '*';
        bool ans = dfs(board, i-1, j, ind+1, word) || dfs(board, i+1, j, ind+1, word) || 
            dfs(board, i, j-1, ind+1, word) || dfs(board, i, j+1, ind+1, word);
        board[i][j] = c;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                
                if(dfs(board, i, j, 0, word)) return true;
            }
        }
        return false;
    }
};
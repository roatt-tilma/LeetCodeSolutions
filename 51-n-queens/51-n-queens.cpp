class Solution {
public:
    
    bool isSafe(int row, int col, vector<string>& board){
        
        for(int i = col-1; i >= 0; i--){
            if(board[row][i] == 'Q') return false;
        }
        
        int i = row-1;
        int j = col-1;
        
        while(i >= 0 && j >= 0){
            if(board[i--][j--] == 'Q') return false;
        }
        
        i = row+1;
        j = col-1;
        
        while(i < board.size() && j >= 0){
            if(board[i++][j--] == 'Q') return false;
        }
        
        return true;
    }
    
    void recurseSolve(int col, vector<string>& board, vector<vector<string>>& ans){
        if(col == board.size()){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < board.size(); row++){
            if(isSafe(row, col, board)){
                board[row][col] = 'Q';
                recurseSolve(col+1, board, ans);
                board[row][col] = '.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i = 0; i < n; i++){
            board[i] = s;
        }
        
        recurseSolve(0, board, ans);
        
        return ans;
    }
};
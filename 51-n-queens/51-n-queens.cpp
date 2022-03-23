class Solution {
public:
    bool check(vector<string> &board, int row, int col, int n){
        int pre_row = row;
        int pre_col = col;
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = pre_row;
        col = pre_col;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        row = pre_row;
        col = pre_col;
        
        while(row < n && col >= 0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    
    void checkForSol(vector<vector<string>> &ans, vector<string> &board, int n, int col){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int i=0; i<n; i++){
            if(check(board, i, col, n)){
                board[i][col] = 'Q';
                checkForSol(ans, board, n, col+1);
                board[i][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n, '.');
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        checkForSol(ans, board, n, 0);
        return ans;
    }
};
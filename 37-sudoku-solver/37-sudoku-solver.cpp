class Solution {
public:
    bool check(vector<vector<char>> &board, int row, int col, int val){
        int pre_row = row;
        int pre_col = col;
        for(int i=0; i<9; i++){
            if(board[row][i] == val){
                return false;
            }
        }
        for(int i=0; i<9; i++){
            if(board[i][col] == val){
                return false;
            }
        }
        int row_dv = row-row%3;
        int col_dv = col-col%3;
        
        for(int i=row_dv; i<row_dv+3; i++){
            for(int j=col_dv; j<col_dv+3; j++){
                if(board[i][j] == val){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool sudoku(vector<vector<char>> &board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    for(int val='1'; val<='9'; val++){
                        if(check(board, i, j, val)){
                            board[i][j] = val;
                            if(sudoku(board)){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board);
    }
};
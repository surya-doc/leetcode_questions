class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        for(int i=0; i<col; i++){
            int start_row = 0;
            int start_col = i;
            vector<int>stor;
            while(start_row<row && start_col<col){
                stor.push_back(mat[start_row][start_col]);
                start_row++;
                start_col++;
            }
            sort(stor.begin(), stor.end());
            start_row = 0;
            start_col = i;
            int posi = 0;
            while(start_row<row && start_col<col){
                mat[start_row][start_col] = stor[posi++];
                start_row++;
                start_col++;
            }
        }
        for(int i=1; i<row; i++){
            int start_row_1 = i;
            int start_col_1 = 0;
            vector<int>stor_1;
            while(start_row_1<row && start_col_1<col){
                stor_1.push_back(mat[start_row_1][start_col_1]);
                start_row_1++;
                start_col_1++;
            }
            sort(stor_1.begin(), stor_1.end());
            start_row_1 = i;
            start_col_1 = 0;
            int posi_1 = 0;
            while(start_row_1<row && start_col_1<col){
                mat[start_row_1][start_col_1] = stor_1[posi_1++];
                start_row_1++;
                start_col_1++;
            }
        }
        return mat;
    }
};
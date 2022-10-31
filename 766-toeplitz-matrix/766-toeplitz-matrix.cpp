class Solution {
public:
    
    bool check(vector<vector<int>> &matrix, int i, int j){
        int prev = matrix[i][j];
        int m = matrix.size();
        int n = matrix[0].size();
        matrix[i][j] = -1;
        while(i < m && j < n){
            if(matrix[i][j] != prev){
                return false;
            }
            matrix[i][j] = -1;
            i++;
            j++;
        }
        return true;
    }
    
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] != matrix[i-1][j-1]){
                    return false;
                }
            }
            cout << "\n";
        }
        return true;
    }
};
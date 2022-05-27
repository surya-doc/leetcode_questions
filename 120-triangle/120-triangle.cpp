class Solution {
public:
    int getPathSum(vector<vector<int>> &tri, int row, int col, vector<vector<int>> &dp){
        // cout << row;
        if(row == tri.size()-1){
            return tri[row][col];
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int down = tri[row][col]+getPathSum(tri, row+1, col, dp);
        int dia = tri[row][col]+getPathSum(tri, row+1, col+1, dp);
        return dp[row][col] = min(down, dia);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int> (n));
        for(int i=0; i<n; i++){
            dp[m-1][i] = triangle[m-1][i];
        }
        for(int i=m-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int down = triangle[i][j]+dp[i+1][j];
                int dia = triangle[i][j]+dp[i+1][j+1];
                dp[i][j] = min(down, dia);
            }
        }
        return dp[0][0];
    }
};
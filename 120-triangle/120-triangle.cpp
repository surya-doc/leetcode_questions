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
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return getPathSum(triangle, 0, 0, dp);
    }
};
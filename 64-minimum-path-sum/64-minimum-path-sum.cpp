class Solution {
public:
    int findPath(vector<vector<int>> &grid, int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i == m-1 && j == n-1){
            return grid[m-1][n-1];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int down = INT_MAX;
        int right = INT_MAX;
        if(i+1 < m){
            down = grid[i][j]+findPath(grid, m , n, i+1, j, dp);
        }
        if(j+1 < n){
            right = grid[i][j]+findPath(grid, m, n, i, j+1, dp);
        }
        // cout << i << " " << j << "->" << min(down, right) << "\n";
        return dp[i][j] = min(down, right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return findPath(grid, m, n, 0, 0, dp);
    }
};
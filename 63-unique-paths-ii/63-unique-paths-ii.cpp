class Solution {
public:
    int findPath(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
        if(i >= grid.size() || j >= grid[0].size() || grid[i][j] == 1){
            return 0;
        }
        
        if(i == grid.size()-1 && j == grid[0].size()-1){
            return 1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right = findPath(grid, i, j+1, dp);
        int down = findPath(grid, i+1, j, dp);
        return dp[i][j] = right+down;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int> (obstacleGrid[0].size(), -1));
        return findPath(obstacleGrid, 0, 0, dp);
    }
};
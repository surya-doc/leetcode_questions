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
        int m = size(obstacleGrid), n = size(obstacleGrid[0]);
	    vector<vector<int> > dp (m, vector<int>(n, 0));
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        dp[0][0] = 1;
        for(int i=1; i<m; i++){
            dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) ? 1 : 0;
        }
        for(int i=1; i<n; i++){
            dp[0][i] = (obstacleGrid[0][i] == 0 && dp[0][i-1] == 1) ? 1 : 0;
        }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                } else {
                    dp[i][j] = 0;
                }
        }
    }
    return dp[m-1][n-1];
    }
};
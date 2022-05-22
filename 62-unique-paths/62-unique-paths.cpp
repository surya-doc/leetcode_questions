class Solution {
public:
    int countPaths(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int down = countPaths(m, n, i+1, j, dp);
        int right = countPaths(m, n, i, j+1, dp);
        return dp[i][j] = down+right;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 1));
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                int up = dp[i-1][j];
                int right = dp[i][j-1];
                dp[i][j] = up+right;
            }
        }
        return dp[m-1][n-1];
    }
};
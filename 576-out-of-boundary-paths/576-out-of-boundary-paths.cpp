class Solution {
public:
    long int mod = 1e9+7;
    // int f(int m, int n, int move, int i, int j, vector<vector<vector<int>>> &dp){
    //     if(i == m || j == n || i < 0 || j < 0){
    //         return 1;
    //     }
    //     if(move <= 0){
    //         return 0;
    //     }
    //     if(dp[i][j][move] != -1){
    //         return dp[i][j][move];
    //     }
    //     int up = f(m, n, move-1, i-1, j, dp)%mod;
    //     int down = f(m, n, move-1, i+1, j, dp)%mod;
    //     int left = f(m, n, move-1, i, j-1, dp)%mod;
    //     int right = f(m, n, move-1, i-1, j+1, dp)%mod;
    //     return dp[i][j][move] = (up+down+left+right)%mod;
    // }
    
//     long int mod = 1e9+7;
   int f(int m, int n, int move, int i, int j, vector<vector<vector<int>>>&dp)
    {
       
        if(i==m || j==n || i<0 || j<0)
            return 1;
    
        if(move<=0) 
            return 0;
       
        if(dp[i][j][move] != -1 ) return dp[i][j][move];
        int up = f(m, n, move-1, i-1, j, dp);
        int down = f(m, n, move-1, i, j-1, dp);
        int left = f(m, n, move-1, i+1, j, dp);
        int right = f(m, n, move-1, i, j+1, dp);
       
        return dp[i][j][move] = (left%mod + right%mod + up%mod + down%mod) % mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (maxMove+1, -1)));
        return f(m, n, maxMove, startRow, startColumn, dp);
    }
};
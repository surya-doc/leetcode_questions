class Solution {
public:
    
    int getTheNumber(int n, int l, string &s, string &t, vector<vector<int>> &dp){
        if(l < 0) return 1;
        if(n < 0) return 0;
        if(dp[n][l] != -1){
            return dp[n][l];
        }
        if(s[n] == t[l]){
            return dp[n][l] = getTheNumber(n-1, l-1, s, t, dp)+getTheNumber(n-1, l, s, t, dp);
        }
        return dp[n][l] = getTheNumber(n-1, l, s, t, dp);
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int l = t.size();
        vector<vector<double>> dp(n+1, vector<double> (l+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<=l; i++){
            dp[0][i] = 0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=l; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][l];
    }
};
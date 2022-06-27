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
        vector<vector<int>> dp(n+1, vector<int> (l+1, -1));
        return getTheNumber(n-1, l-1, s, t, dp);
    }
};
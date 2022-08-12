class Solution {
public:
    
    int getLen(string &s, int k, int indx, char ch, vector<vector<int>> &dp){
        if(indx >= s.size()){
            return 0;
        }
        if(dp[indx][ch] != -1){
            return dp[indx][ch];
        }
        int not_take = 0+getLen(s, k, indx+1, ch, dp);
        int take = 0;
        if(ch == '$' || abs((97-ch)-(97-s[indx])) <= k){
            take = 1+getLen(s, k, indx+1, s[indx], dp);
        }
        return dp[indx][ch] = max(take, not_take);
    }
    
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.size(), vector<int> (150, -1));
        return getLen(s, k, 0, '$', dp);
    }
};
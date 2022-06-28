class Solution {
public:
    
    bool getMatch(string &p, string &s, int i, int j, vector<vector<int>> &dp){
        if(i < 0 && j < 0){
            return true;
        }
        if(i < 0 && j >= 0){
            return false;
        }
        if(j < 0){
            for(int a=0; a<=i; a++){
                if(p[a] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(p[i] == s[j] || p[i] == '?'){
            return dp[i][j] = getMatch(p, s, i-1, j-1, dp);
        }
        if(p[i] == '*'){
            return dp[i][j] = getMatch(p, s, i-1, j, dp) | getMatch(p, s, i, j-1, dp);
        }
        return false;
    }
    
    bool isMatch(string s, string p) {
        int l1 = p.size();
        int l2 = s.size();
        vector<vector<int>> dp(l1+1, vector<int> (l2+1, -1));
        return getMatch(p, s, l1-1, l2-1, dp);
    }
};
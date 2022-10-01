class Solution {
public:
    
    int getNum(string s, int i, vector<int> &dp){
        if(dp[i] != -1){
            return dp[i];
        }
        if(i >= s.size()){
            return dp[i] = 1;
        }
        if(s[i] == '0'){
            return dp[i] = 0;
        }
        int take_two = 0;
        int take_one = 0;
        if(i<s.size()-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) take_two = getNum(s, i+2, dp);
        take_one = getNum(s, i+1, dp);
        return dp[i] = take_one+take_two;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        return getNum(s, 0, dp);
    }
};
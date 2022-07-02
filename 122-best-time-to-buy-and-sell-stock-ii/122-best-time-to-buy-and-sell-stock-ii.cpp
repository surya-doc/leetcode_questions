class Solution {
public:
    
    int getVal(vector<int> &p, int n, int indx, int buy, vector<vector<int>> &dp){
        if(indx == n) return 0;
        if(dp[indx][buy] != -1){
            return dp[indx][buy];
        }
        int profit = 0;
        if(buy){
            profit = max(-p[indx]+getVal(p, n, indx+1, 0, dp), 0+getVal(p, n, indx+1, 1, dp));
        }
        else{
            profit = max(p[indx]+getVal(p, n, indx+1, 1, dp), 0+getVal(p, n, indx+1, 0, dp));
        }
        return dp[indx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        dp[n][0] = dp[n][1] = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=1; j++){
                int profit = 0;
                if(j){
                    profit = max(-prices[i]+dp[i+1][0], 0+dp[i+1][1]);
                }
                else{
                    profit = max(prices[i]+dp[i+1][1], 0+dp[i+1][0]);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};
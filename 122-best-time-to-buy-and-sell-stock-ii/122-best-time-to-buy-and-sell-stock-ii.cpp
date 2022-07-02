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
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return getVal(prices, n, 0, 1, dp);
    }
};
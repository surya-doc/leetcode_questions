class Solution {
public:
    
    int getTheProfit(vector<int> &prices, int fee, int indx, int buy, vector<vector<int>> &dp){
        if(indx == prices.size()){
            return 0;
        }
        if(dp[indx][buy] != -1){
            return dp[indx][buy];
        }
        int profit = 0;
        if(buy){
            profit = max(prices[indx]+getTheProfit(prices, fee, indx+1, 0, dp)-fee, getTheProfit(prices, fee, indx+1, buy, dp));
        }
        else{
            profit = max(-prices[indx]+getTheProfit(prices, fee, indx+1, 1, dp), getTheProfit(prices, fee, indx+1, buy, dp));
        }
        return dp[indx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return getTheProfit(prices, fee, 0, 0, dp);
    }
};
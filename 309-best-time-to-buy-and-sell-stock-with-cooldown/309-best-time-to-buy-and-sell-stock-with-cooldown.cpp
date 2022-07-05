class Solution {
public:
    
    int getPrice(vector<int> &p, int indx, int buy, vector<vector<int>> &dp){
        if(indx >= p.size()){
            return 0;
        }
        if(dp[indx][buy] != -1){
            return dp[indx][buy];
        }
        int prft = 0;
        if(buy){
            prft = max(p[indx]+getPrice(p, indx+2, 0, dp), 0+getPrice(p, indx+1, 1, dp));
        }
        else{
            prft = max(-p[indx]+getPrice(p, indx+1, 1, dp), 0+getPrice(p, indx+1, 0, dp));
        }
        return dp[indx][buy] = prft;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return getPrice(prices, 0, 0, dp);
    }
};
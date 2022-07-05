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
        vector<vector<int>> dp(n+2, vector<int> (2, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=1; j++){
                int prft = 0;
                if(j){
                    prft = max(prices[i]+dp[i+2][0], 0+dp[i+1][1]);
                }
                else{
                    prft = max(-prices[i]+dp[i+1][1], 0+dp[i+1][0]);
                }
                dp[i][j] = prft;
            }
        }
        return getPrice(prices, 0, 0, dp);
    }
};
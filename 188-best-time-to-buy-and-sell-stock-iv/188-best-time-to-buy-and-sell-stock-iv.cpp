class Solution {
public:
    
    int getPrice(vector<int> &p, int indx, int buy, int no, int k, vector<vector<vector<int>>> &dp){
        if(indx == p.size() || no >= k){
            return 0;
        }
        if(dp[indx][buy][no] != -1){
            return dp[indx][buy][no];
        }
        int prft = 0;
        if(buy){
            prft = max(p[indx]+getPrice(p, indx+1, 0, no+1, k, dp), 0+getPrice(p, indx+1, 1, no, k, dp));
        }
        else{
            prft = max(-p[indx]+getPrice(p, indx+1, 1, no, k, dp), 0+getPrice(p, indx+1, 0, no, k, dp));
        }
        return dp[indx][buy][no] = prft;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k, -1)));
        return getPrice(prices, 0, 0, 0, k, dp);
    }
};
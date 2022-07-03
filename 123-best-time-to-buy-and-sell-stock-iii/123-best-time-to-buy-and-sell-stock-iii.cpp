class Solution {
public:
    
    int getPrice(vector<int> &p, int indx, int buy, int no, vector<vector<vector<int>>> &dp){
        if(indx == p.size() || no >= 2){
            return 0;
        }
        if(dp[indx][buy][no] != -1){
            return dp[indx][buy][no];
        }
        int prft = 0;
        if(buy){
            prft = max(p[indx]+getPrice(p, indx+1, 0, no+1, dp), 0+getPrice(p, indx+1, 1, no, dp));
        }
        else{
            prft = max(-p[indx]+getPrice(p, indx+1, 1, no, dp), 0+getPrice(p, indx+1, 0, no, dp));
        }
        return dp[indx][buy][no] = prft;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, -0)));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=1; j++){
                for(int k=1; k<=2; k++){
                    int prft = 0;
                    if(j==1){
                        prft = max(-prices[i]+dp[i+1][0][k], 0+dp[i+1][1][k]);
                    }
                    else{
                        prft = max(prices[i]+dp[i+1][1][k-1], 0+dp[i+1][0][k]);
                    }
                    dp[i][j][k] = prft;
                }
            }
        }
        return dp[0][1][2];
    }
};
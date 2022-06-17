class Solution {
public:
    int countCoins(vector<int> &coins, int amount, int indx, vector<vector<int>> &dp){
        if(indx == coins.size() || amount <= 0){
            if(amount == 0){
                return 0;
            }
            else{
                return INT_MAX-1;
            }
        }
        int ans = -1;
        if(dp[indx][amount] != -1) return dp[indx][amount];
        if(coins[indx] > amount){
            ans = 0+countCoins(coins, amount, indx+1, dp);
        }
        else{
            int not_take = 0+countCoins(coins, amount, indx+1, dp);
            int take = 1+countCoins(coins, amount-coins[indx], indx, dp);
            ans = min(not_take, take);
        }
        return dp[indx][amount] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int m = amount;
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = (j == 0) ? 0 : INT_MAX-1;
                }
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                if(j < coins[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
                }
            }
        }
        if(dp[n][m] == INT_MAX-1){
            return -1;
        }
        else{
            return dp[n][m];
        }
    }
};
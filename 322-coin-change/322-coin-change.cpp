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
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        int ans = countCoins(coins, amount, 0, dp);
        if(ans == INT_MAX-1) return -1;
        return ans;
    }
};
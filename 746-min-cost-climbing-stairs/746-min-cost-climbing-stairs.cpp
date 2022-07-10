class Solution {
public:
    
    int getVal(vector<int> &cost, int indx, vector<int> &dp){
        if(indx >= cost.size()){
            return 0;
        }
        if(dp[indx] != -1){
            return dp[indx];
        }
        int one_step = getVal(cost, indx+1, dp);
        int two_step = getVal(cost, indx+2, dp);
        
        return dp[indx] = cost[indx]+min(one_step, two_step);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2, 0);
        dp[n] = 0;
        for(int i=n-1; i>=0; i--){
            int one_step = dp[i+1];
            int two_step = dp[i+2];
            dp[i] = cost[i]+min(one_step, two_step);
        }
        return min(dp[0], dp[1]);
    }
};
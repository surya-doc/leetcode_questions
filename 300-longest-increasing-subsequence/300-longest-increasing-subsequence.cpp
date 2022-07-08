class Solution {
public:
    
    int getLength(vector<int> &num, int indx, int prev, vector<vector<int>> &dp){
        if(indx >= num.size()){
            return 0;
        }
        if(dp[indx][prev+1] != -1){
            return dp[indx][prev+1];
        }
        int take = 0;
        if(prev == -1 || num[indx] > num[prev]){
            take = 1+getLength(num, indx+1, indx, dp);
        }
        int not_take = 0+getLength(num, indx+1, prev, dp);
        return dp[indx][prev+1] = max(take, not_take);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int i=n-1; i>= 0; i--){
            for(int j=i-1; j>=-1; j--){
                int not_take = 0+dp[i+1][j+1];
                if(j == -1 || nums[i] > nums[j]){
                    not_take = max(not_take, 1+dp[i+1][i+1]);
                }
                dp[i][j+1] = not_take;
            }
        }
        return dp[0][-1+1];
    }
};
class Solution {
public:
    
    int getAns(vector<int> &nums, int indx, int prev, vector<int> &dp){
        if(indx >= nums.size()){
            return 0;
        }
        if(dp[prev+1] != -1){
            return dp[prev+1];
        }
        int not_take = getAns(nums, indx+1, prev, dp);
        int take = 0;
        if(prev == -1 || nums[indx] > nums[prev]){
            take = 1+getAns(nums, indx+1, indx, dp);
        }
        return dp[prev+1] = max(take, not_take);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return getAns(nums, 0, -1, dp);
    }
};
class Solution {
public:
    
    int getSumNumber(vector<int> &nums, int sum, int target, int indx, vector<int> &dp){
        if(sum == target){
            return 1;
        }
        if(sum > target || indx >= nums.size()){
            return 0;
        }
        int ans = 0;
        if(dp[sum] != -1){
            return dp[sum];
        }
        for(int i=0; i<nums.size(); i++){
            ans += getSumNumber(nums, sum+nums[i], target, i, dp);
        }
        return dp[sum] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target, -1);
        return getSumNumber(nums, 0, target, 0, dp);
    }
};
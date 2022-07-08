class Solution {
public:
    
//     int getLength(vector<int> &num, int indx, int prev, vector<vector<int>> &dp){
//         if(indx >= num.size()){
//             return 0;
//         }
//         if(dp[indx][prev+1] != -1){
//             return dp[indx][prev+1];
//         }
//         int take = 0;
//         if(prev == -1 || num[indx] > num[prev]){
//             take = 1+getLength(num, indx+1, indx, dp);
//         }
//         int not_take = 0+getLength(num, indx+1, prev, dp);
//         return dp[indx][prev+1] = max(take, not_take);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int> (n+1, -1));
//         return getLength(nums, 0, -1, dp);
//     }
    vector<vector<int>> dp;
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(size(nums), vector<int>(1+size(nums), -1));   // dp[i][j] denotes max LIS starting from i when nums[j] is previous picked element
        return solve(nums, 0, -1);
    }
    int solve(vector<int>& nums, int i, int prev_i) {
        if(i >= size(nums)) return 0;
        if(dp[i][prev_i+1] != -1) return dp[i][prev_i+1];
        int take = 0, dontTake = solve(nums, i + 1, prev_i);
        if(prev_i == -1 || nums[i] > nums[prev_i]) take = 1 + solve(nums, i + 1, i); // try picking current element if no previous element is chosen or current > nums[prev_i]
        return dp[i][prev_i+1] = max(take, dontTake);
    }
};

// vector<vector<int>> dp;
//     int lengthOfLIS(vector<int>& nums) {
//         dp.resize(size(nums), vector<int>(1+size(nums), -1));   // dp[i][j] denotes max LIS starting from i when nums[j] is previous picked element
//         return solve(nums, 0, -1);
//     }
//     int solve(vector<int>& nums, int i, int prev_i) {
//         if(i >= size(nums)) return 0;
//         if(dp[i][prev_i+1] != -1) return dp[i][prev_i+1];
//         int take = 0, dontTake = solve(nums, i + 1, prev_i);
//         if(prev_i == -1 || nums[i] > nums[prev_i]) take = 1 + solve(nums, i + 1, i); // try picking current element if no previous element is chosen or current > nums[prev_i]
//         return dp[i][prev_i+1] = max(take, dontTake);
//     }
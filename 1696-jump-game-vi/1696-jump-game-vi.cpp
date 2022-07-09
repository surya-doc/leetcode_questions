class Solution {
public:
    
    int getTheJump(vector<int> &nums, int k, int indx, vector<int> &dp){
        if(dp[indx] != INT_MIN){
            return dp[indx];
        }
        for(int i=1; i<=k; i++){
            if(indx+i < nums.size()){
                dp[indx] = max(dp[indx], nums[indx]+getTheJump(nums, k, indx+i, dp));
            }
        }
        return dp[indx];
    }
    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        multiset<int> ms({dp[0] = nums[0]});
        for(int i=1; i<n; i++){
            if(i > k){
                ms.erase(ms.find(dp[i-k-1]));
            }
            ms.insert(dp[i] = *rbegin(ms)+nums[i]);
        }
        return dp[n-1];
    }
};
class Solution {
public:
    int dp[201][10001];
    
    int getAns(vector<int> &nums, int n, int ans){
        if(ans==0)
            return 1;
        if(n==0)
            return 0;
        if(dp[n][ans]!=-1)  
            return dp[n][ans];
        if(nums[n-1]<=ans)
            return dp[n][ans]=getAns(nums,n-1,ans-nums[n-1])||getAns(nums,n-1,ans);
        
        return dp[n][ans]=getAns(nums,n-1,ans);
    }
    
    bool canPartition(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += nums[i];
        }
        if(ans%2 != 0) return false;
        ans /= 2;
        memset(dp, -1, sizeof(dp));
        return getAns(nums, nums.size()-1, ans);
    }
};
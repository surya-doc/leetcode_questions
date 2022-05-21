class Solution {
public:
    int calc(vector<int> &num){
        int n = num.size();       
        vector<int> dp(n);
        // int temp = num[0];
        dp[0] = num[0];
        for(int i=1; i<n; i++){
            int take = num[i];
            if(i > 1){
                take += dp[i-2];
            }
            int not_take = dp[i-1];
            dp[i] = max(take, not_take);
            // cout << dp[i];
        }
        cout << endl << dp[n-1];
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0; i<nums.size()-1; i++){
            temp1.push_back(nums[i]);
        }
        for(int i=1; i<nums.size(); i++){
            temp2.push_back(nums[i]);
        }
        int ans = max(calc(temp1), calc(temp2));
        return ans;
    }
};
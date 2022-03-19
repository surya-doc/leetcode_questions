class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int i=0, j=0;
        int ans = 0;
        int dp = 0;
        int prev = -1;
        for(; j<nums.size(); j++){
            if(nums[j] < left){
                ans += dp;
            }
            else if(nums[j] > right){
                dp = 0;
                prev = j;
            }
            else if(nums[j] >= left && nums[j] <= right){
                dp = j-prev;
                ans += dp;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> dp;
    int ans = 0;
    int getMaxLength(vector<int> &nums1, vector<int> &nums2, int indx1, int indx2){
        if(indx1 < 0 || indx2 < 0){
            return 0;
        }
        if(dp[indx1][indx2] != -1){
            return dp[indx1][indx2];
        }
        getMaxLength(nums1, nums2, indx1-1, indx2);
        getMaxLength(nums1, nums2, indx1, indx2-1);
        if(nums1[indx1] == nums2[indx2]){
            dp[indx1][indx2] = 1+getMaxLength(nums1, nums2, indx1-1, indx2-1);
        }
        else{
            dp[indx1][indx2] = 0;
        }
        ans = max(ans, dp[indx1][indx2]);
        return dp[indx1][indx2];
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(), vector<int> (nums2.size(), -1));
        getMaxLength(nums1, nums2, nums1.size()-1, nums2.size()-1);
        return ans;
    }
};
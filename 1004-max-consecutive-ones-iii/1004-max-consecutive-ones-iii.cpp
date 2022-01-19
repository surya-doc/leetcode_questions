class Solution {
public:
    int getAns(vector<int> &nums, int k, int ans){
        int l = 0;
        int temp_k = k;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                temp_k--;
            }
            while(temp_k < 0){
                if(nums[l] == 0){
                    temp_k++;
                }
                l++;
            }
            ans = max(ans, (i-l+1));
        }
        return ans;
    }
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        ans = getAns(nums, k, ans);
        return ans;
    }
};
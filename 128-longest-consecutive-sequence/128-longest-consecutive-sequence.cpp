class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int temp = 1;
        if(nums.size() == 0 || nums.size() == 1){
            return nums.size();
        }
        int prev = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]-prev == 1){
                temp++;
            }
            else if(nums[i]-prev > 1){
                temp = 1;
            }
            ans = max(temp, ans);
            prev = nums[i];
        }
        return ans;
    }
};
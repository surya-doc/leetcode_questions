class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int avg = nums[nums.size()/2];
        int ans = 0;
        // for(auto it:nums){
        //     avg += it;
        // }
        // avg /= (nums.size());
        
        for(auto it:nums){
            ans += abs(it-avg);
        }
        return ans;
    }
};
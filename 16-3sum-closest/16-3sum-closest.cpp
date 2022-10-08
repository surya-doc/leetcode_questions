class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        for(int l=0; l<nums.size()-2; ++l){
            if(l > 0 && nums[l] == nums[l-1]){
                continue;
            }
            int mid = l+1;
            int r = nums.size()-1;
            while(mid < r){
                int sum = nums[l]+nums[mid]+nums[r];
                if(sum == target){
                    return sum;
                }
                if(abs(target-ans) > abs(target-sum)){
                    ans = sum;
                }
                if(sum > target){
                    --r;
                }
                else{
                    ++mid;
                }
            }
        }
        return ans;
    }
};
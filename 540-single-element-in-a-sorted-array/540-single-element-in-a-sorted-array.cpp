class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int ans;
        if(nums.size() == 1){
            return nums[0];
        }
        while(l < r){
            int mid = l+(r-l)/2;
            int next;
            if(mid%2 == 0){
                next = mid+1;
            }
            else{
                next = mid-1;
            }
            if(nums[next] == nums[mid]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return nums[l];
    }
};
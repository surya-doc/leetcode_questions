class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int i = 0;
        int sum = 0;
        sort(nums.begin(), nums.end());
        while(nums[i] < 0 && k>0 && i<nums.size()){
            nums[i] = -nums[i];
            i++;
            k--;
        }
        if(k>0){
            sort(nums.begin(), nums.end());
            if(k%2 == 0){
                k = 0;
            }
            else{
                nums[0] = -nums[0];
                k = 0;
            }
        }
        for(auto it:nums){
            sum += it;
        }
        return sum;
    }
};
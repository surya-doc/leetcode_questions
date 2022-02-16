class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int first_ignore = 1;
        int i = 0;
        int j = 0;
        int max_sum = 0;
        int temp_sum = 0;
        int first_zero_occurance = -1;
        for(; j<nums.size(); j++){
            if(nums[j] == 0){
                if(first_ignore == 1){
                    first_ignore = 0;
                    first_zero_occurance = j;
                }
                else{
                    temp_sum = j-first_zero_occurance-1;
                    i = first_zero_occurance+1;
                    first_zero_occurance  =j;
                }
            }
            else{
                temp_sum += nums[j];
                max_sum = max(temp_sum, max_sum);
            }
        }
        if(first_zero_occurance == -1) max_sum--;
        return max_sum;
    }
};
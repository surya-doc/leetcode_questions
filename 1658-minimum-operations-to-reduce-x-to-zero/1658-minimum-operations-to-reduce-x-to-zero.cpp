class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans = INT_MIN;
        int sum = -x;
        for(auto i:nums) sum+=i;
        if(sum == 0) return nums.size();
        int len = 0;
        int temp_sum = 0;
        int temp_len = 0;
        int j = 0;
        if(sum < 0) return -1;
        for(int i=0; i<nums.size(); i++){
            
                temp_sum += nums[i];
                temp_len++;
            
            if(temp_sum > sum){
                while(temp_sum > sum){
                    temp_sum -= nums[j++];
                    temp_len--;
                }
            }
            if(temp_sum == sum){
                ans = max(ans, temp_len);
            }
        }
        if(ans == INT_MIN) return -1;
        return nums.size()-ans;
    }
};
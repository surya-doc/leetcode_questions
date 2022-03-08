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
            int temp_min = INT_MAX;
            for(auto it:nums){
                temp_min = min(temp_min, it);
                sum += it;
            }
        if(k>0){
            cout << sum;
            if(k%2 == 0){
                k = 0;
            }
            else{
                sum -= temp_min;
                temp_min = -temp_min;
                sum += temp_min;
                k = 0;
            }
        }
        return sum;
    }
};
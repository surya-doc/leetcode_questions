class Solution {
public:
    bool isValid(vector<int> &nums, int mid, int thrsld){
        int sum = 0;
        // cout << mid << " ";
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < mid){
                sum += 1;
            }
            else{
                // cout << nums[i]/float(mid) << " " << ceil(nums[i]/float(mid)) << " ";
                sum += ceil(nums[i]/float(mid));
            }
        }
        // cout << sum << "\n";
        if(sum <= thrsld) return true;
        return false;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int max_val = 0;
        for(int i=0; i<nums.size(); i++){
            max_val = max(max_val, nums[i]);
        }
        int l = 1;
        int r = max_val;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(isValid(nums, mid, threshold)){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};
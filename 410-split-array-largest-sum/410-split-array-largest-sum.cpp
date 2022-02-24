class Solution {
public:
    bool isValid(vector<int> &nums, int mid, int m){
        cout << mid << " " << "\n";
        int sum = 0;
        int subL = 1;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum > mid){
                // cout << sum << " ";
                subL += 1;
                sum = nums[i];
            }
        }
        cout << "\n";
        if(subL <= m) return true;
        return false;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int l = -1;
        int r = 0;
        int total_sum = 0;
        for(auto it:nums){
            l = max(l, it);
            r += it;
        }
        int ans = -1;
        cout << l << r;
        total_sum = r;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(isValid(nums, mid, m)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
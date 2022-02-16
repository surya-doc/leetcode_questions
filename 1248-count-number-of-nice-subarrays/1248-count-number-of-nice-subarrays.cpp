class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0, j=0;
        int k1 = k-1;
        cout << k << k1;
        int n = nums.size();
        int count = 0;
        int count1 = 0;
        int ans = 0;
        for(; j<n; j++){
            k -= nums[j]%2;
            while(k < 0){
                k += nums[i++]%2;
            }
            count = count+j-i+1;
        }
        i=0;
        j=0;
        for(; j<n; j++){
            k1 -= nums[j]%2;
            while(k1 < 0){
                k1 += nums[i++]%2;
            }
            count1 = count1+j-i+1;
        cout << count1 << "\n";
        }
        ans = count-count1;
        return ans;
    }
};
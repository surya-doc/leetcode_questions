class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int len = n*(n+1)/2;
        int ans = 0;
        for(int i=1; i<n; i++){
            nums[i] = nums[i]+nums[i-1];
        }
        vector<int>newArr;
        int var = -1;
        int temp = n;
        int place = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(var < 0){
                    newArr.push_back(nums[j]);
                }
                else{
                    newArr.push_back(nums[j]-nums[var]);
                }
            }
            var++;
        }
        sort(newArr.begin(), newArr.end());
        // for(int i=0; i<len; i++){
        //     cout << nums[i] << " ";
        // }
        for(int i=left-1; i<right; i++){
            ans = (ans+newArr[i])%(1000000007);
        }
        return ans;
    }
};
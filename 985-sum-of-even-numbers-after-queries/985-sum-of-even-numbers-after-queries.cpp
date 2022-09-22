class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> ans;
        for(auto it:nums){
            if(it%2 == 0){
                sum += it;
            }
        }
        for(int i=0; i<queries.size(); i++){
            int ind = queries[i][1];
            int val = queries[i][0];
            cout << sum << " ";
            if(nums[ind]%2 == 0){
                sum -= nums[ind];
            }
            nums[ind] += val;
            if(nums[ind]%2 == 0){
                sum += nums[ind];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
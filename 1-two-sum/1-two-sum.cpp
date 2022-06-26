class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        map<int, int> count;
        vector<int> ans;
        // for(int i=0; i<nums.size(); i++){
        //     mp[nums[i]] = i+1;
        //     count[nums[i]]++;
        // }
        for(int i=0; i<nums.size(); i++){
            int rem = target-nums[i];
            if(mp[rem]){
                ans.push_back(mp[rem]-1);
                ans.push_back(i);
                break;
            }
            mp[nums[i]] = i+1;
        }
        return ans;
    }
};
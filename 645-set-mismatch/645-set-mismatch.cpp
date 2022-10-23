class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> stor(nums.size(), 0);
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            stor[nums[i]-1] += 1;
            if(stor[nums[i]-1] > 1){
                ans.push_back(nums[i]);
            }
        }
        for(int i=0; i<nums.size(); i++){
            cout << stor[i] << " ";
            if(stor[i] == 0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
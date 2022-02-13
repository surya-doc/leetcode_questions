class Solution {
public:
    void findSubset(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int i){
        // cout << i;
        
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        findSubset(nums, temp, ans, i+1);
        temp.pop_back();
        findSubset(nums, temp, ans, i+1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        findSubset(nums, temp, ans, 0);
        return ans;
    }
};
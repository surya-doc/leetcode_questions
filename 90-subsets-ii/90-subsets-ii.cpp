class Solution {
public:
    void getSubset(vector<int> &nums, int i, vector<int> &temp, vector<vector<int>> &ans, int n){
            ans.push_back(temp);
        //     return;
        // }
        for(int j=i; j<n; j++){
            if(j != i && nums[j] == nums[j-1]){
                continue;
            }
            temp.push_back(nums[j]);
            getSubset(nums, j+1, temp, ans, n);
            temp.pop_back();
        }

    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        getSubset(nums, 0, temp, ans, n);
        return ans;
    }
};
class Solution {
public:
    void getSubset(vector<int> nums, int i, vector<int> temp, set<vector<int>> &st, int n){
        if(i == n){
            st.insert(temp);
            return;
        }
        getSubset(nums, i+1, temp, st, n);
        temp.push_back(nums[i]);
        getSubset(nums, i+1, temp, st, n);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> temp;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        getSubset(nums, 0, temp, st, n);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
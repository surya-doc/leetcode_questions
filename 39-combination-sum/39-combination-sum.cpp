class Solution {
public:
    void getTheCombinations(vector<int>& candidates, vector<vector<int>> &ans, int target, vector<int> &temp, int index, int temp_sum){
        // if(temp_sum > target){
        //     return;
        // }
        if(index == candidates.size()){
            if(temp_sum == target){
                ans.push_back(temp);
            }
            return;
        }
        // for(int i=index; i<candidates.size(); i++){
        //     temp.push_back(candidates[i]);
        //     getTheCombinations(candidates, ans, target, temp, i, temp_sum+candidates[i]);
        //     temp.pop_back();
        // }
        if(temp_sum <= target){
            temp.push_back(candidates[index]);
            getTheCombinations(candidates, ans, target, temp, index, temp_sum+candidates[index]);
            temp.pop_back();
        }
        
        getTheCombinations(candidates, ans, target, temp, index+1, temp_sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        // map<int, int>mp;
        vector<int>temp;
        getTheCombinations(candidates, ans, target, temp, 0, 0);
        return ans;
    }
};
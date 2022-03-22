class Solution {
public:
    void getList(vector<int> &cand, int taregt, vector<vector<int>> &ans, vector<int> &temp, int idx){
        if(taregt == 0){
            ans.push_back(temp);
            return;
        }
        for(int i=idx; i<cand.size(); i++){
            if(i>idx && cand[i] == cand[i-1]) continue;
            if(cand[i] > taregt) break;
            temp.push_back(cand[i]);
            getList(cand, taregt-cand[i], ans, temp, i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        getList(candidates, target, ans, temp, 0);
        return ans;
    }
};
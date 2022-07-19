class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp(1, 1);
        ans.push_back(temp);
        if(numRows == 1){
            return ans;
        }
        for(int i=2; i<=numRows; i++){
            vector<int> prev = ans[i-2];
            vector<int> p;
            p.push_back(1);
            for(int j=0; j<i-2; j++){
                p.push_back(prev[j]+prev[j+1]);
            }
            p.push_back(1);
            ans.push_back(p);
        }
        return ans;
    }
};
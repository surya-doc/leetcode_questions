class Solution {
public:
    static bool reOrder(vector<int> &x, vector<int> &y){
        if(x[0] != y[0]) return x[0] > y[0];
        return x[1] < y[1];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people){
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), reOrder);
        for(int i=0; i<people.size(); i++){
            ans.insert(ans.begin()+people[i][1], people[i]);
        }
        return ans;
    }
};
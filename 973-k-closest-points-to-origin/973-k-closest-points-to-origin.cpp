class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b){
        int a_x = a[0]*a[0]+a[1]*a[1];
        int b_x = b[0]*b[0]+b[1]*b[1];
        return a_x < b_x;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> ans;
        sort(points.begin(), points.end(), compare);
        for(auto it:points){
            cout << it[0] << it[1] << " ";
        }
        
        for(auto it:points){
            if(!k) break;
            ans.push_back({it[0], it[1]});
                k--;
        }
        
        return ans;
    }
};
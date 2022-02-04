class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long>mp;
        long long ans = 0;
        for(auto it:rectangles){
            double temp = (double)it[0]/(double)it[1];
            if(mp[temp]) ans+=mp[temp];
            mp[temp]++;
        }
        return ans;
    }
};
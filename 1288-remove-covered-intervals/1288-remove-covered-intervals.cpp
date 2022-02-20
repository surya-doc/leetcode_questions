class Solution {
public:
    static bool order(vector<int> &a, vector<int> &b){
        if(a[0] != b[0]){
            return a[0] < b[0];  
        }
        return a[1] > b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 1;
        int left = 0;
        int right = 0;
        sort(intervals.begin(), intervals.end(), order);
        left = intervals[0][0];
        right = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] >= left && intervals[i][1] <= right){
                continue;
            }
            else{
                ans++;
                left = min(intervals[i][0], left);
                right = max(intervals[i][1], right);
            }
        }
        return ans;
    }
};